#include <windows.h>
#include <winuser.h>

void getcoords(int &x, int &y);

bool equals(int n1, int n2);

int MiddleMouseKeyPressed(){
    return (GetAsyncKeyState( VK_MBUTTON ) & 0x8000) != 0;
}

using namespace std;

int main() {
    int x,y;
    int x2,y2;
    int dx,dy;

    SetCursorPos(-50,-50);
    int minx,miny;
    getcoords(minx,miny);

    SetCursorPos(9999,9999);
    int mx,my;
    getcoords(mx,my);

    while(true) {
        while(MiddleMouseKeyPressed()){
            getcoords(x,y);
            Sleep(3);
            getcoords(x2,y2);

            if(equals(x,mx)) {
            x = x-2;
            }

            if(equals(x2,mx)) {
            x2 = x2-2;
            }

            if(equals(y2,my)) {
            y2 = y2-2;
            }

            if(equals(y,my)) {
            y = y-2;
            }

            if(equals(x,minx)) {
            x = x+2;
            }

            if(equals(x2,minx)) {
            x2 = x2+2;
            }

            if(equals(y2,miny)) {
            y2 = y2+2;
            }

            if(equals(y,miny)) {
            y = y+2;
            }

            SetCursorPos(x2,y2);

            dx = x2 - x;
            dy = y2 - y;
            SetCursorPos(x-dx,y-dy);

        }
    }


    return 0;
}


    bool equals(int n1, int n2) {
    if(abs(n1-n2) < 3) {
        return true;
    }
    else {
        return false;
    }

}

    void getcoords(int &x, int &y) {
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        x = cursorPos.x;
        y = cursorPos.y;
    }
