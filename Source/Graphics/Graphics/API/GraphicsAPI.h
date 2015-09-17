#pragma once


namespace WickedSick
{
  
  class Model;
  class Shader;
  struct GraphicsOptions;
  class Window;
  enum APIType;


  class GraphicsAPI
  {
  public:

    GraphicsAPI(APIType api);
    virtual ~GraphicsAPI();

    virtual void Initialize(GraphicsOptions* options,
                            Window* window) = 0;
    virtual void CleanUp() = 0;

    virtual void BeginScene() = 0;
    virtual void RenderScene() = 0;
    virtual void EndScene() = 0;

    virtual Model* MakeModel() = 0;
    virtual Shader* MakeShader() = 0;
    
  protected:
    GraphicsOptions* options_;

    virtual void clear_buffers() = 0;
    APIType api_;

  };
}