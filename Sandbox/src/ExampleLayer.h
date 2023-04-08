#pragma once

#include "Aurora.h"

class ExampleLayer : public Aurora::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Aurora::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Aurora::Event& e) override;
private:
	Aurora::ShaderLibrary m_ShaderLibrary;
	Aurora::Ref<Aurora::Shader> m_Shader;
	Aurora::Ref<Aurora::VertexArray> m_VertexArray;

	Aurora::Ref<Aurora::Shader> m_FlatColorShader;
	Aurora::Ref<Aurora::VertexArray> m_SquareVA;

	Aurora::Ref<Aurora::Texture2D> m_Texture, m_ChernoLogoTexture;

	Aurora::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
#pragma once
