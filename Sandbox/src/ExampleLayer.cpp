#include "ExampleLayer.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

ExampleLayer::ExampleLayer()
	: Layer("ExampleLayer"), m_CameraController(1280.0f / 720.0f)
{
	m_VertexArray = Aurora::VertexArray::Create();

	float vertices[3 * 7] = {
		-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
		 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
		 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
	};

	Aurora::Ref<Aurora::VertexBuffer> vertexBuffer = Aurora::VertexBuffer::Create(vertices, sizeof(vertices));
	Aurora::BufferLayout layout = {
		{ Aurora::ShaderDataType::Float3, "a_Position" },
		{ Aurora::ShaderDataType::Float4, "a_Color" }
	};
	vertexBuffer->SetLayout(layout);
	m_VertexArray->AddVertexBuffer(vertexBuffer);

	uint32_t indices[3] = { 0, 1, 2 };
	Aurora::Ref<Aurora::IndexBuffer> indexBuffer = Aurora::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
	m_VertexArray->SetIndexBuffer(indexBuffer);

	m_SquareVA = Aurora::VertexArray::Create();

	float squareVertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
	};

	Aurora::Ref<Aurora::VertexBuffer> squareVB = Aurora::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
	squareVB->SetLayout({
		{ Aurora::ShaderDataType::Float3, "a_Position" },
		{ Aurora::ShaderDataType::Float2, "a_TexCoord" }
		});
	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	Aurora::Ref<Aurora::IndexBuffer> squareIB = Aurora::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
	m_SquareVA->SetIndexBuffer(squareIB);

	m_Shader = Aurora::Shader::Create("VertexPosColor", "assets/shaders/Base.glsl");

	m_FlatColorShader = Aurora::Shader::Create("FlatColor", "assets/shaders/FlatColor.glsl");

	auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

	m_Texture = Aurora::Texture2D::Create("assets/textures/Checkerboard.png");
	m_ChernoLogoTexture = Aurora::Texture2D::Create("assets/textures/ChernoLogo.png");

	textureShader->Bind();
	textureShader->SetInt("u_Texture", 0);
}

void ExampleLayer::OnAttach()
{
}

void ExampleLayer::OnDetach()
{
}

void ExampleLayer::OnUpdate(Aurora::Timestep ts)
{
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Aurora::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Aurora::RenderCommand::Clear();

	Aurora::Renderer::BeginScene(m_CameraController.GetCamera());

	glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

	m_FlatColorShader->Bind();
	m_FlatColorShader->SetFloat3("u_Color", m_SquareColor);

	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
			glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
			Aurora::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
		}
	}

	auto textureShader = m_ShaderLibrary.Get("Texture");

	m_Texture->Bind();
	Aurora::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
	m_ChernoLogoTexture->Bind();
	Aurora::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	// Triangle
	// Aurora::Renderer::Submit(m_Shader, m_VertexArray);

	Aurora::Renderer::EndScene();
}

void ExampleLayer::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void ExampleLayer::OnEvent(Aurora::Event& e)
{
	m_CameraController.OnEvent(e);
}