#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
{
}

void Sandbox2D::OnAttach()
{
	AUR_PROFILE_FUNCTION();

	m_CheckerboardTexture = Aurora::Texture2D::Create("assets/textures/Background.jpg");
}

void Sandbox2D::OnDetach()
{
	AUR_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Aurora::Timestep ts)
{
	AUR_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);
	
	// Render
	Aurora::Renderer2D::ResetStats();
	{
		AUR_PROFILE_SCOPE("Renderer Prep");
		Aurora::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Aurora::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		AUR_PROFILE_SCOPE("Renderer Draw");
		Aurora::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Aurora::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Aurora::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Aurora::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		Aurora::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 1.0f);
		Aurora::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 1.0f);
		Aurora::Renderer2D::EndScene();

		Aurora::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Aurora::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Aurora::Renderer2D::EndScene();
	}



	// TODO: Add these functions - Shader::SetMat4, Shader::SetFloat4
	// std::dynamic_pointer_cast<Aurora::OpenGLShader>(m_FlatColorShader)->Bind();
	// std::dynamic_pointer_cast<Aurora::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);
}

void Sandbox2D::OnImGuiRender()
{
	AUR_PROFILE_FUNCTION();

	ImGui::Begin("Settings");

	auto stats = Aurora::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Aurora::Event& e)
{
	m_CameraController.OnEvent(e);
}
