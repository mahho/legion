#ifndef __CEVENTRECEIVER_H_
#define __CEVENTRECEIVER_H_

//#ifdef MINGW
    #include <irrlicht/irrlicht.h>
//#else
//    #include <irrlicht.h>
//#endif

class CEventReceiver : public IEventReceiver
{
public:
        struct SMouseState
        {
                core::position2di Position;
                core::position2di OldPosition;
                bool LeftButtonDown;
                bool RightButtonDown;
                SMouseState() : LeftButtonDown(false),  RightButtonDown(false) { }
        } MouseState;

        // This is the one method that we have to implement
        virtual bool OnEvent(const SEvent& event)
        {
                // Remember whether each key is down or up
                if (event.EventType == irr::EET_KEY_INPUT_EVENT)
                        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

          // Remember the mouse state
                if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
                {
                        switch(event.MouseInput.Event)
                        {
                        case EMIE_LMOUSE_PRESSED_DOWN:
                                MouseState.LeftButtonDown = true;
                                break;

                        case EMIE_LMOUSE_LEFT_UP:
                                MouseState.LeftButtonDown = false;
                                break;
                                
                        case EMIE_RMOUSE_PRESSED_DOWN:
								MouseState.RightButtonDown = true;
								break;
								
						case EMIE_RMOUSE_LEFT_UP:
								MouseState.RightButtonDown = false;
								break;
								
                        case EMIE_MOUSE_MOVED:
								MouseState.OldPosition.X = MouseState.Position.X;
								MouseState.OldPosition.Y = MouseState.Position.Y;
                                MouseState.Position.X = event.MouseInput.X;
                                MouseState.Position.Y = event.MouseInput.Y;
                                break;

                     break;
                        default:
                                // We won't use the wheel
                                break;
                        }
                }

                return false;
        }

        // This is used to check whether a key is being held down
        virtual bool IsKeyDown(EKEY_CODE keyCode) const
        {
                return KeyIsDown[keyCode];
        }

        CEventReceiver()
        {
                for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
                        KeyIsDown[i] = false;
        }

        const SMouseState & getMouseState(void) const
        {
                return MouseState;
        }

private:
        // We use this array to store the current state of each key
        bool KeyIsDown[KEY_KEY_CODES_COUNT];
};


#endif
