#include "LogicPrecompiled.h"
#include "Core/CoreInterface.h"
#include "Graphics/GraphicsInterface.h"
#include "Window/WindowInterface.h"
#include "Input/InputInterface.h"
#include "Utility/UtilityInterface.h"

#include "Testing/TestingInterface.h"
#include "ObjectFactory/ObjectFactoryInterface.h"

#include "EventSystem/EventSystemInterface.h"

int main(void)
{
  

  WickedSick::MemoryManager<int> memory;

  WickedSick::Engine* engine = new WickedSick::Engine();

  engine->AddSystem(new WickedSick::Window());
  engine->AddSystem(new WickedSick::Graphics());
  engine->AddSystem(new WickedSick::Input());
  engine->AddSystem(new WickedSick::EventSystem());
  engine->AddSystem(new WickedSick::ObjectFactory());
  

  engine->Initialize();
  engine->Load();

  WickedSick::ObjectFactory* fact = (WickedSick::ObjectFactory*)engine->GetSystem(WickedSick::ST_ObjectFactory);
  fact->CreateArchetypes();
  fact->BuildScene();

  while (engine->IsActive())
  {
    engine->Update();
  }

  delete engine;

  return 0;
}

