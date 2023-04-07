#include <Aurora.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Aurora::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Aurora::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		Aurora::Ref<Aurora::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Aurora::VertexBuffer::Create(vertices, sizeof(vertices)));
		Aurora::BufferLayout layout = {
			{ Aurora::ShaderDataType::Float3, "a_Position" },
			{ Aurora::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		Aurora::Ref<Aurora::IndexBuffer> indexBuffer;
		indexBuffer.reset(Aurora::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Aurora::VertexArray::Create());

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Aurora::Ref<Aurora::VertexBuffer> squareVB;
		squareVB.reset(Aurora::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Aurora::ShaderDataType::Float3, "a_Position" },
			{ Aurora::ShaderDataType::Float2, "a_TexCoord" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Aurora::Ref<Aurora::IndexBuffer> squareIB;
		squareIB.reset(Aurora::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		//´´½¨Shader
		m_Shader.reset(Aurora::Shader::Create("assets/shaders/Base.glsl"));
		m_FlatColorShader.reset(Aurora::Shader::Create("assets/shaders/FlatColor.glsl"));
		m_TextureShader.reset(Aurora::Shader::Create("assets/shaders/Texture.glsl"));

		//m_Texture = Aurora::Texture2D::Create("assets/textures/Checkerboard.png");
		m_Texture = Aurora::Texture2D::Create("assets/textures/Background.jpg");
		//m_ChernoLogoTexture = Aurora::Texture2D::Create("assets/textures/ChernoLogo.png");AuroraEngineIcon
		m_AuroraLogoTexture = Aurora::Texture2D::Create("assets/textures/AuroraEngineIcon.png");

		std::dynamic_pointer_cast<Aurora::OpenGLShader>(m_TextureShader)->Bind();
		std::dynamic_pointer_cast<Aurora::OpenGLShader>(m_TextureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(Aurora::Timestep ts) override
	{
		if (Aurora::Input::IsKeyPressed(AUR_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		else if (Aurora::Input::IsKeyPressed(AUR_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (Aurora::Input::IsKeyPressed(AUR_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;
		else if (Aurora::Input::IsKeyPressed(AUR_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		if (Aurora::Input::IsKeyPressed(AUR_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		if (Aurora::Input::IsKeyPressed(AUR_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed * ts;

		Aurora::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Aurora::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Aurora::Renderer::BeginScene(m_Camera);

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Aurora::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Aurora::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Aurora::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		m_Texture->Bind();
		Aurora::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		//m_ChernoLogoTexture->Bind();
		m_AuroraLogoTexture->Bind();
		Aurora::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));


		Aurora::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(Aurora::Event& event) override
	{
	}
private:
	Aurora::Ref<Aurora::Shader> m_Shader;
	Aurora::Ref<Aurora::VertexArray> m_VertexArray;

	Aurora::Ref<Aurora::Shader> m_FlatColorShader, m_TextureShader;
	Aurora::Ref<Aurora::VertexArray> m_SquareVA;

	Aurora::Ref<Aurora::Texture2D> m_Texture, m_AuroraLogoTexture;// m_ChernoLogoTexture;

	Aurora::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
	glm::vec4 m_FontColor = { 0.0f, 0.0f, 0.0f ,1.0f };
};

class Sandbox : public Aurora::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Aurora::Application* Aurora::CreateApplication()
{
	return new Sandbox();
}