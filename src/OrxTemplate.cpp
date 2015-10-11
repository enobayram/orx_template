#define __SCROLL_IMPL__ // This definition causes the Scroll symbols to be compiled with this unit

#include "OrxTemplate.h"

class Soldier: public ScrollObject {
    enum {LEFT, RIGHT} direction;
public:
    Soldier(): direction(RIGHT) {}

    void OnCreate() {}
    void OnDelete() {}

    void Update(const orxCLOCK_INFO &_rstInfo) {
        if(orxInput_IsActive("Click")) {
            orxVECTOR mouseInView;
            orxVECTOR mouseInWorld;
            orxVIEWPORT * viewport = OrxTemplate::GetInstance().GetMainViewport();
            orxMouse_GetPosition(&mouseInView);
            bool inWorld = orxRender_GetWorldPosition(&mouseInView, viewport, &mouseInWorld);
            if(inWorld) {
		orxVECTOR myPos;
                GetPosition(myPos);
                if(mouseInWorld.fX > myPos.fX) {
                    direction = RIGHT;
                    SetAnim("WalkRight");
                    orxVECTOR speed = {50,0,0};
                    SetSpeed(speed);
                } else {
                    direction = LEFT;
                    SetAnim("WalkLeft");
                    orxVECTOR speed = {-50,0,0};
                    SetSpeed(speed);
                }
            } 
        } else {
            orxVECTOR speed = {0,0,0};
            SetSpeed(speed);
            if(direction == RIGHT) SetAnim("IdleRight");
            else SetAnim("IdleLeft");
        }
    }
};

void OrxTemplate::BindObjects () {
    ScrollBindObject<Soldier> ("Soldier");
}

orxSTATUS OrxTemplate::Init () {
    CreateObject("Soldier");
    return orxSTATUS_SUCCESS;
}

orxSTATUS OrxTemplate::Run ()
{
    orxSTATUS eResult = orxSTATUS_SUCCESS;

    return eResult;
}

void OrxTemplate::Update(const orxCLOCK_INFO &_rstInfo) {
}

void OrxTemplate::Exit() {
}

OrxTemplate::OrxTemplate() {

}

int main(int argc, char* argv[]) {

    OrxTemplate::GetInstance().Execute(argc, argv);

    return EXIT_SUCCESS;
}
