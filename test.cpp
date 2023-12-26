#include <windows.h>
#include <iostream>
#include <utility>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;


float T_moverocket = 0;
float T_moveplanetX = 0;
float T_moveplanetY = 0;
float T_moveplanetAngle = 0;
float T_moverover = 0;
float T_moveboatX = 0;
float T_moveboatY = 0;
float T_movespaceshipX = 0;
float T_movewatercurrentX = 0;

float T_blinkAngle = 0;
float T_movewalleX = 0;


pair<float, float> P1[4] = {{670, 230}, {600, 220}, {590, 170}, {630, 130}};
pair<float, float> P2[4] = {{670, 230}, {620, 220}, {720, 170}, {680, 130}};
float f1 = 1, f2 = 1;


struct T_Color
{
    int r;
    int g;
    int b;
};


struct T_Scene
{
    string T_scene;
    T_Color T_skyColor;
    T_Color T_landColor;
    T_Color T_riverColor; 
    T_Color T_darkrocksColor;
    T_Color T_lightrocksColor;
    T_Color T_stoneholderColor;
    T_Color T_hubsColor;
    T_Color T_hubshadowColor;
    T_Color T_hubdoorsColor;
    T_Color T_hubroof;
    T_Color T_hubdarkColor;
    T_Color T_ladderColor;
    T_Color T_hubgrillsColor;
    T_Color T_towerbodyColor;
    T_Color T_towershadowColor;
    T_Color T_towerglassColor;
    T_Color T_bridgeColor;
    T_Color T_bridgelayersColor;
    T_Color T_bridgeboltsColor;
    T_Color T_bridgeshadowColor;
    T_Color T_rocketbodyColor;
    T_Color T_rocketshadeColor;
    T_Color rocketouterlines;
    T_Color T_planetColor;
    T_Color T_planetLayers;
    T_Color T_rovermetalColor;
    T_Color T_roverdarkmetalColor;
    T_Color T_roverwindowColor;
    T_Color T_roverlightsColor;
    T_Color T_roverwheelsColor;
    T_Color T_roverwheelscrewColor;
    T_Color T_roverlightmetalColor;
    T_Color T_roveroutlinesColor;
    T_Color T_boatColor;
    T_Color T_boatbottomColor;
    T_Color T_boatwindowColor;
    T_Color T_spaceshipbodyColor;
    T_Color T_spaceshipwindowColor;
    T_Color T_spaceshiplayersColor;
    T_Color T_spaceshipoutlinesColor;
    T_Color T_rivershade1Color;
    T_Color T_rivershade2Color;
    T_Color T_rivershade3Color;
    T_Color T_rivershade4Color;
    T_Color T_starsColor;
    T_Color T_radarbodyColor;
    T_Color T_radarColor;
    T_Color T_radaroutlinesColor;
    T_Color T_transmitterbodyColor;
    T_Color T_transmitteroutlinesColor;
    T_Color T_transmittersignalColor;
    T_Color T_transmitantennaColor;
    T_Color T_steelbodyColor;
    T_Color T_wallebodyColor;
    T_Color T_walleshadowColor;
    T_Color T_solarpanelColor;
    T_Color T_walleoutlinesColor;

};

T_Scene night =
{
    "night",
    {48, 89, 124},      //skycolor
    {37, 31, 67},       //landcolor
    {68,121,207},       //rivercolor
    {25,10,29},         //darkrockscolor
    {60,65,114},        //lightrockscolor
    {37,31,67},         //stoneholder
    {37, 65, 102},      //hubscolor
    {33, 54, 82},       //hubsshadowcolor
    {225, 203, 19},     //hubdoorscolor
    {212, 212, 232},    //hubroofcolor
    {26, 43, 65},       //hubdarkcolor
    {255, 255, 255},    //laddercolor
    {0, 0, 0},          //hubgrillscolor
    {255, 255, 255},    //towerbodycolor
    {175, 186, 230},      //towershadowcolor
    {73, 189, 231},       //towerglasscolor
    {255, 255, 255},       //bridgecolor
    {175,186,230},      //bridgelayerscolor
    {225, 203, 19},     //bridgeboltscolor
    {175,186,230},      //bridgeshadowcolor
    {147, 152, 158},    //rocketbodycolor
    {255, 255, 255},    //rocketshadecolor
    {147, 152, 158},    //rocketouterlinescolor
    {219, 202, 135},    //planetcolor
    {24, 101, 70},      //planetlayers
    {94,97,103},        //rovermetalcolor
    {35,39,43},         //roverdarkmetalcolor
    {11,76,104},        //roverwindowcolor
    {212,133,105},      //roverlightscolor
    {138,138,138},      //roverwheelscolor
    {61,62,64},         //roverwheelsscrewcolor
    {210,211,213},      //roverlightmetalcolor
    {0, 0, 0},         //roveroutlinescolor
    {255, 255, 255},    //boatcolor
    {39,30,73},         //boatbottomcolor
    {107,111,116},      //boatwindowcolor
    {226,225,231},      //spaceshipbodycolor
    {50,50,48},         //spaceshipwindowcolor
    {50,50,48},         //spaceshiplayercolor
    {0, 0, 0},          //spaceshipoutlinecolor
    {61, 109, 186},     //rivershade1color
    {54,102,192},       //rivershade2color
    {33, 59, 122},      //rivershade3color
    {110,161,233},      //rivershade4color
    {255, 255, 255},    //starscolor
    {178,15,17},        //radarbodycolor
    {0, 255, 0},        //radarcolor
    {37,31,67},         //radarouterlinescolor
    {171, 178, 185},    //transmitterbodycolor
    {0, 0, 0},          //transmitterouterlinescolor
    {255, 255, 255},    //transmittersignalcolor
    {255, 0, 0},        //transmitterantennacolor
    {166, 172, 175},    //transmittersteelbodycolor
    {168,159,150},      //wallebodycolor
    {82,63,68},         //walleshadowcolor
    {130,167,210},      //solarpanelcolor
    {0, 0, 0}

};


// animations function logics
void T_animateRocket(int val)
{
    T_moverocket += 5;

    if (T_moverocket > 1200)
    {
        T_moverocket = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, T_animateRocket, 0);
}


void T_animatePlanets(int val)
{
    T_moveplanetX += 0.5;
    T_moveplanetY -= 0.5;

    if (T_moveplanetY < -1000)
    {
        T_moveplanetX = 0;
        T_moveplanetY = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, T_animatePlanets, 0);
}



void T_animateRoverLeft(int val)
{
    T_moverover -= 1;

    if (T_moverover < -1300)
    {
        T_moverover = 700;
    }
    glutPostRedisplay();
    glutTimerFunc(20, T_animateRoverLeft, 0);
}

void T_animateBoatLeft(int val)
{
    T_moveboatX -= 5;
    T_moveboatY += 0.5;

    if (T_moveboatX < -2200)
    {
        T_moveboatX = 0;
        T_moveboatY = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, T_animateBoatLeft, 0);
}

void T_animateSpaceshipLeft(int val)
{
    T_movespaceshipX -= 2;

    if (T_movespaceshipX < -2200)
    {
        T_movespaceshipX = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, T_animateSpaceshipLeft, 0);
}

void T_animateWaterCurrentRight(int val)
{
    T_movewatercurrentX += 2;

    if (T_movewatercurrentX > 400)
    {
        T_movewatercurrentX = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, T_animateWaterCurrentRight, 0);

}

void T_animateBlinkCircle(int val)
{
    T_blinkAngle += 2.0f;

    if(T_blinkAngle > 360.0)
    {
        T_blinkAngle -= 360;
    }
    glutPostRedisplay();                //Notify GLUT that the display has changed
    glutTimerFunc(20, T_animateBlinkCircle, 0);      //Notify GLUT to call update again in 25 milliseconds
}

void T_animateWalleRight(int val)
{
    T_movewalleX += 3;

    if (T_movewalleX > 2200)
    {
        T_movewalleX = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, T_animateWalleRight, 0);
}


// Custom Functions
void T_points1(vector<pair<float, float>> coord, T_Color T_Color = {255,255,255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glPointSize(2);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3ub(T_Color.r, T_Color.g, T_Color.b);
    glBegin(GL_POINTS);
    for (int i = 0; i < coord.size(); i++) {
        glVertex2f(Tx + s * coord[i].first, Ty + s * coord[i].second);
    }
    glEnd();
}

void T_points2(vector<pair<float, float>> coord, T_Color T_Color = {255,255,255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glPointSize(4);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3ub(T_Color.r, T_Color.g, T_Color.b);
    glBegin(GL_POINTS);
    for (int i = 0; i < coord.size(); i++) {
        glVertex2f(Tx + s * coord[i].first, Ty + s * coord[i].second);
    }
    glEnd();
}

void T_points3(vector<pair<float, float>> coord, T_Color T_Color = {255,255,255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glPointSize(10);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3ub(T_Color.r, T_Color.g, T_Color.b);
    glBegin(GL_POINTS);
    for (int i = 0; i < coord.size(); i++) {
        glVertex2f(Tx + s * coord[i].first, Ty + s * coord[i].second);
    }
    glEnd();
}

void T_polygon(vector<pair<float, float>> coord, T_Color T_Color = {255,255,255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(T_Color.r, T_Color.g, T_Color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < coord.size(); i++) {
        glVertex2f(Tx + s * coord[i].first, Ty + s * coord[i].second);
    }
    glEnd();
}


void T_halfcircle(float radius, float Tx, float Ty, T_Color T_Color = {255,255,255})
{
    glBegin(GL_POLYGON);
    for(int i=0; i<250; i++){
        glColor3ub(T_Color.r, T_Color.g, T_Color.b);
        float pi = 1.5708;
        float A = (i*2*pi)/250;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+Tx, y+Ty);
    }
    glEnd();
}


void T_halfcircleBorder(float radius, float Tx, float Ty, T_Color T_Color = {255,255,255})
{
    glPointSize(0.1);
    glBegin(GL_POINTS);
    for(int i=0; i<250; i++){
        glColor3ub(T_Color.r, T_Color.g, T_Color.b);
        float pi = 1.5708;
        float A = (i*2*pi)/250;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+Tx, y+Ty);
    }
    glEnd();
}

void T_fullcircle(float radius, float Tx, float Ty, T_Color T_Color = {255,255,255})
{
    glBegin(GL_POLYGON);
    for(int i=0; i<250; i++){
        glColor3ub(T_Color.r, T_Color.g, T_Color.b);
        float pi = 3.1416;
        float A = (i*2*pi)/250;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+Tx, y+Ty);
    }
    glEnd();
}

void T_fullcircleBorder(float radius, float Tx, float Ty, T_Color T_Color = {255,255,255})
{
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int i=0; i<250; i++){
        glColor3ub(T_Color.r, T_Color.g, T_Color.b);
        float pi = 3.1416;
        float A = (i*2*pi)/250;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+Tx, y+Ty);
    }
    glEnd();
}


void T_linestrip(vector<pair<float, float>> coord, T_Color T_Color = {255,255,255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glLineWidth(1);
    glColor3ub(T_Color.r, T_Color.g, T_Color.b);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < coord.size(); i++) {
        glVertex2f(Tx + s * coord[i].first, Ty + s * coord[i].second);
    }
    glEnd();
}


void T_Fire(pair<float, float> P1[], pair<float, float> P2[])
{
    pair<float, float> a[120], b[120];
    for (int i = 0; i < 120; i++)
    {
        a[i].first = pow((1 - i / 120.0), 3) * P1[0].first + 3 * i / 120.0 * pow((1 - i / 120.0), 2) * P1[1].first + 3 * (1 - i / 120.0) * pow(i / 120.0, 2) * P1[2].first + pow(i / 120.0, 3) * P1[3].first;
        a[i].second = pow((1 - i / 120.0), 3) * P1[0].second + 3 * i / 120.0 * pow((1 - i / 120.0), 2) * P1[1].second + 3 * (1 - i / 120.0) * pow(i / 120.0, 2) * P1[2].second + pow(i / 120.0, 3) * P1[3].second;
        b[i].first = pow((1 - i / 120.0), 3) * P2[0].first + 3 * i / 120.0 * pow((1 - i / 120.0), 2) * P2[1].first + 3 * (1 - i / 120.0) * pow(i / 120.0, 2) * P2[2].first + pow(i / 120.0, 3) * P2[3].first;
        b[i].second = pow((1 - i / 120.0), 3) * P2[0].second + 3 * i / 120.0 * pow((1 - i / 120.0), 2) * P2[1].second + 3 * (1 - i / 120.0) * pow(i / 120.0, 2) * P2[2].second + pow(i / 120.0, 3) * P2[3].second;
    }
    glColor3ub(248, 196, 113);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 120; i++)
    {
        glVertex2f(-480 + a[i].first, 115 + a[i].second);
        glVertex2f(-480 + b[i].first, 115 + b[i].second);
    }
    glEnd();
    glColor3ub(212, 172, 13);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 120; i++)
    {
        glVertex2f(-150 + a[i].first * 0.5, 180 + a[i].second * 0.5);
        glVertex2f(-150 + b[i].first * 0.5, 180 + b[i].second * 0.5);
    }
    glEnd();
    glColor3ub(252, 243, 207);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 120; i++)
    {
        glVertex2f(15 + a[i].first * 0.25, 215 + a[i].second * 0.25);
        glVertex2f(15 + b[i].first * 0.25, 215 + b[i].second * 0.25);
    }
    glEnd();
}

void T_blinkingCircle(float Tx, float Ty, T_Color blink = {0, 255, 0})
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(Tx, Ty, 0);
    glRotatef(T_blinkAngle, 0, 0, 0);

    glLineWidth(5);
    glBegin(GL_POINTS);                          // Draw a Red 1x1 Square centered at origin

    for(int i=0; i<200; i++)
    {
        glColor3ub(0, 255, 0);
        float pi = 3.1416;
        float A = (i*2*pi)/200;
        float r = 20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}


void T_blinkingWalleEyes(float Tx, float Ty, T_Color blink = {0, 255, 0})
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(Tx, Ty, 0);
    glRotatef(T_blinkAngle, 0, 0, 0);

    glBegin(GL_POLYGON);                          // Draw a Red 1x1 Square centered at origin

    for(int i=0; i<200; i++)
    {
        glColor3ub(0, 255, 0);
        float pi = 3.1416;
        float A = (i*2*pi)/200;
        float r = 5;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}




// Project functions

void T_sky(T_Color T_skyColor = {48, 89, 124})
{
    // upper limits of the T_river to top
    T_polygon({{0, 470},{1920, 470},{1920, 1080},{0, 1080}}, T_skyColor, 0, 0);
}

void T_land(T_Color T_landColor = {37,31,67})
{
    // Function Call
    T_polygon({{1047, 0},{1047, 159},{910, 207},{354, 253},{0, 253},{0, 0}}, T_landColor, 0, 0);
    T_polygon({{965, 184},{981, 307},{1045, 383},{1149, 449},{849, 378},{834, 351},{352, 250},{311, 184}}, T_landColor, 0, 0);
    T_polygon({{1017, 189},{1048, 221},{1078, 307},{1123, 328},{1139, 378},{1078, 390},{1020, 362},{981, 310},{992, 207}}, T_landColor, 0, 0);
    T_polygon({{1920, 0},{1920, 124},{1674, 164},{1584, 145},{1561, 207},{1347, 141},{1230, 141},{1077, 182},{953, 76},{0, 0}}, T_landColor, 0, 0);

    //far T_lands
    T_polygon({{1683, 470},{1556, 470},{1501, 420},{1501, 383},{1571, 377},{1613, 356},{1690, 364},}, T_landColor);
    T_polygon({{1690, 364},{1743, 377},{1826, 356},{1920, 364},{1920, 470},{1622, 470},}, T_landColor);

}

void T_river(T_Color T_riverColor = {68,121,207}, T_Color T_landColor = {37,31,67}, T_Color T_darkrocksColor = {25,10,29})
{
    //very far T_lands

    //2
    T_polygon({{1066, 395},{1054, 482},{1030, 489},{1000, 531},{973, 536},{950, 549},{935, 541},{934, 395}}, T_landColor);
    //1
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor);

    // translated to different positions
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, -100, -25);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, -200, 10);
    T_polygon({{1066, 395},{1054, 482},{1030, 489},{1000, 531},{973, 536},{950, 549},{935, 541},{934, 395}}, T_landColor, -400);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, -400, -10);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, -600 -5);
    T_polygon({{1066, 395},{1054, 482},{1030, 489},{1000, 531},{973, 536},{950, 549},{935, 541},{934, 395}}, T_landColor, -600);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, -700, 10);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, -800, 30);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, -900);

    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, 200);
    T_polygon({{1066, 395},{1054, 482},{1030, 489},{1000, 531},{973, 536},{950, 549},{935, 541},{934, 395}}, T_landColor, 200);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, 250);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, 300);
    T_polygon({{1066, 395},{1054, 482},{1030, 489},{1000, 531},{973, 536},{950, 549},{935, 541},{934, 395}}, T_landColor, 400);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, 400);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, 520, -25);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, 600, 30);
    T_polygon({{1066, 395},{1054, 482},{1030, 489},{1000, 531},{973, 536},{950, 549},{935, 541},{934, 395}}, T_landColor, 600, 30);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, 700, 20);
    T_polygon({{1066, 395},{1054, 482},{1030, 489},{1000, 531},{973, 536},{950, 549},{935, 541},{934, 395}}, T_landColor, 700, 20);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, 800, 10);
    T_polygon({{1066, 395},{1054, 482},{1030, 489},{1000, 531},{973, 536},{950, 549},{935, 541},{934, 395}}, T_landColor, 800, 15);
    T_polygon({{810, 405},{961, 398},{984, 455},{923, 549},{886, 519},{858, 525},{838, 492},{822, 487},{803, 442}}, T_landColor, 900, 12);
    T_polygon({{1066, 395},{1054, 482},{1030, 489},{1000, 531},{973, 536},{950, 549},{935, 541},{934, 395}}, T_landColor, 900, 10);





    T_polygon({{1920, 0},{1920, 470},{0, 470},{0, 0}}, T_riverColor, 0, 0);


    T_polygon({{664, 319},{750, 297},{829, 311},{884, 311},{938, 338}}, T_landColor, -600, 140);
    T_polygon({{664, 319},{750, 297},{829, 311},{884, 311},{938, 338}}, T_landColor, -200, 155);
    T_polygon({{664, 319},{750, 297},{829, 311},{884, 311},{938, 338}}, T_landColor, -800, 140);

}

void T_darkrocks(T_Color T_darkrocksColor = {25,10,29})
{
    T_polygon({{660, 312},{836, 348},{656, 330}}, T_darkrocksColor, 0, 0);
    T_polygon({{1017, 188},{1050, 220},{1100, 293},{1136, 364},{1114, 356},{1007, 308},{998, 204}}, T_darkrocksColor, 0, 0);
    T_polygon({{1101, 308},{1154, 328},{1153, 303},{1130, 255},{1101, 275}}, T_darkrocksColor, -15, 35);
    T_polygon({{832, 341},{988, 335},{866, 358},{850, 375}}, T_darkrocksColor, 0, 0);
    T_polygon({{1086, 391},{1106, 387},{1147, 447},{1100, 412}}, T_darkrocksColor, 0, 0);
    T_polygon({{955, 372},{1064, 381},{1025, 362},{1031, 374}}, T_darkrocksColor, 3, 0);
    T_polygon({{465, 234},{518, 243},{896, 214},{423, 220}}, T_darkrocksColor, 0, 0);
    T_polygon({{681, 108},{748, 122},{1031, 163},{923, 131}}, T_darkrocksColor, -3, 2);
    T_polygon({{1462, 79},{1052, 108},{1103, 81},{1078, 56}}, T_darkrocksColor, 0, 0);
    T_polygon({{783, 38},{1075, 58},{1071, 68}}, T_darkrocksColor, 15, 0);
    T_polygon({{958, 186},{900, 207},{946, 214},{974, 253},{967, 184}}, T_darkrocksColor, 0, 0);
    T_polygon({{954, 213},{997, 202},{990, 300},{971, 285}}, T_darkrocksColor, 8, 10);
    T_polygon({{964, 228},{953, 188},{999, 207}}, T_darkrocksColor, 9, 0);

    T_polygon({{85, 216},{143, 207},{208, 215},{259, 236},{170, 234}}, T_darkrocksColor, -20, -20);
    T_polygon({{85, 216},{143, 207},{208, 215},{259, 236},{170, 234}}, T_darkrocksColor, -100, -550, 3);

    T_polygon({{1427, 141},{1634, 124},{1879, 129},{1589, 152}}, T_darkrocksColor);



    // far rocks
    T_polygon({{1501, 383},{1571, 377},{1613, 356},{1690, 364},{1654, 317},{1607, 290},{1582, 326},{1512, 339},}, T_darkrocksColor);
    T_polygon({{1690, 364},{1745, 337},{1770, 315},{1804, 337},{1802, 381},{1800, 447},}, T_darkrocksColor, -100, -50);
    T_polygon({{1713, 424},{1722, 358},{1790, 322},{1815, 371},{1870, 430},}, T_darkrocksColor, -30, -30);
    T_polygon({{1713, 424},{1722, 358},{1790, 322},{1815, 371},{1870, 430},}, T_darkrocksColor, 40, 0);
    T_polygon({{1707, 392},{1681, 358},{1760, 343},{1823, 317},{1868, 396},}, T_darkrocksColor, 70, 0);

    // far rocks shade
    T_polygon({{1234, 469},{1236, 484},{1249, 494},{1249, 479},{1259, 465}}, T_darkrocksColor, -30, 40);
    T_polygon({{1134, 510},{1187, 548},{1172, 518}}, T_darkrocksColor, -65, -10);
    T_polygon({{525, 469},{545, 492},{710, 469}}, T_darkrocksColor, -80, 10);




}

void T_lightrocks(T_Color T_lightrocksColor = {60,65,114})
{
    T_polygon({{656, 332},{837, 350},{720, 351}}, T_lightrocksColor, 0, -2);
    T_polygon({{1002, 304},{1084, 342},{1133, 358},{1141, 380},{1064, 393},{1027, 364}}, T_lightrocksColor, 5, -2);
}

void T_specialstoneholder(T_Color T_stoneholderColor = {37,31,67})
{
    T_polygon({{88, 242},{151, 241},{146, 314},{183, 381},{115, 322}}, T_stoneholderColor, -20, -10);
    T_polygon({{89, 247},{119, 297},{102, 356},{134, 424},{69, 356}}, T_stoneholderColor, -10, -20);

    T_polygon({{268, 327},{203, 249},{257, 246}}, T_stoneholderColor, 0, -10);
    T_polygon({{268, 327},{208, 379},{230, 276}}, T_stoneholderColor, 0, -10);


}




void T_researchHub1(T_Color T_hubsColor = {37, 65, 102}, T_Color T_hubshadowColor = {33, 54, 82}, T_Color T_hubdoorsColor = {225, 203, 19}, T_Color T_hubroof = {212, 212, 232})
{
    //1st
    T_polygon({{1557, 173},{1491, 155},{1491, 108},{1557, 98},{1618, 108},{1618, 155}}, T_hubsColor);
    T_polygon({{1507, 108},{1507, 85},{1534, 83},{1544, 87},{1544, 102}}, T_hubsColor);
    T_polygon({{1545, 80},{1561, 76},{1561, 100},{1545, 100}}, T_hubsColor);

    // shade
    T_polygon({{1560, 98},{1618, 108},{1618, 155},{1560, 145}}, T_hubshadowColor);
    T_polygon({{1534, 83},{1544, 87},{1543, 102},{1534, 102},}, T_hubshadowColor);
    //2nd
    T_polygon({{1616, 157},{1562, 139},{1562, 58},{1632, 43},{1656, 58},{1656, 153}}, T_hubsColor);

    //3rd
    T_polygon({{1656, 58},{1725, 45},{1757, 70},{1757, 148},{1693, 156},{1679, 150},{1656, 152}}, T_hubsColor);

    //2nd shadow
    T_polygon({{1632, 127},{1632, 44},{1658, 59},{1658, 139}}, T_hubshadowColor);

    //3rd shadow
    T_polygon({{1727, 128},{1727, 47},{1757, 71},{1757, 147}}, T_hubshadowColor);

    //roofs
    T_polygon({{1557, 162},{1521, 152},{1557, 146},{1594, 154}}, T_hubshadowColor);
    T_halfcircle(49, 1709, 133, T_hubsColor);
    T_polygon({{1616, 148},{1587, 136},{1625, 128},{1657, 141}}, T_hubshadowColor);

    //doors
    T_polygon({{1566, 81},{1566, 59},{1628, 45},{1628, 69}}, T_hubdoorsColor);
    T_polygon({{1528, 128},{1528, 107},{1539, 105},{1539, 128}}, T_hubdoorsColor, 0, 2);
    T_polygon({{1528, 128},{1528, 107},{1539, 105},{1539, 128}}, T_hubdoorsColor, 15, -3);
    T_polygon({{1643, 99},{1643, 87},{1649, 89},{1649, 102}}, T_hubdoorsColor);
    T_polygon({{1660, 82},{1660, 59},{1681, 56},{1681, 78}}, T_hubdoorsColor);
    T_polygon({{1660, 82},{1660, 59},{1681, 56},{1681, 78}}, T_hubdoorsColor, 40, 30);
    T_polygon({{1660, 82},{1660, 59},{1681, 56},{1681, 78}}, T_hubdoorsColor, -60, 30);
    T_polygon({{1726, 71},{1726, 47},{1741, 59},{1741, 82}}, T_hubdoorsColor, 5, 2);
}



void T_researchHub2(T_Color T_hubsColor = {37, 65, 102}, T_Color T_hubshadowColor = {33, 54, 82}, T_Color T_hubdoorsColor = {225, 203, 19}, T_Color T_hubdarkColor = {26, 43, 65})
{
    T_polygon({{1627, 623},{1627, 487},{1712, 478},{1725, 482},{1725, 623}}, T_hubshadowColor);
    T_polygon({{1627, 623},{1627, 562},{1674, 555},{1674, 621}}, T_hubshadowColor);
    T_polygon({{1657, 619},{1633, 619},{1633, 610},{1657, 610}}, T_hubdoorsColor);
    T_polygon({{1628, 571},{1603, 566},{1603, 489},{1712, 477},{1710, 611},{1656, 615},{1656, 568}}, T_hubshadowColor);
    T_polygon({{1725, 435},{1775, 451},{1775, 623},{1711, 612},{1711, 478},{1711, 437}}, T_hubsColor);

    //roof
    T_polygon({{1712, 611},{1775, 623},{1703, 629},{1656, 624}}, T_hubshadowColor);
    T_polygon({{1669, 631},{1629, 623},{1702, 619},{1723, 628}}, T_hubshadowColor);

    //darker part
    T_polygon({{1619, 488},{1619, 447},{1677, 436},{1687, 440},{1687, 480}}, T_hubdarkColor);
    T_polygon({{1687, 440},{1687, 480},{1725, 476},{1725, 435}}, T_hubdarkColor);
    T_polygon({{1725, 482},{1711, 477},{1725, 474}}, T_hubdarkColor);

    //Windows & Doors
    T_polygon({{1660, 535},{1660, 492},{1704, 486},{1704, 531}}, T_hubdoorsColor);
    T_polygon({{1681, 591},{1681, 564},{1703, 561},{1703, 589}}, T_hubdoorsColor);
    T_polygon({{1758, 611},{1758, 560},{1765, 563},{1765, 614}}, T_hubdoorsColor);
    T_polygon({{1765, 544},{1742, 536},{1742, 496},{1765, 504}}, T_hubdoorsColor);
    T_polygon({{1689, 475},{1689, 441},{1704, 438},{1704, 474}}, T_hubdoorsColor);
}


void T_researchHub3(T_Color T_hubsColor = {37, 65, 102}, T_Color T_hubshadowColor = {33, 54, 82}, T_Color T_hubdoorsColor = {225, 203, 19}, T_Color T_hubdarkColor = {26, 43, 65}, T_Color T_ladderColor = {255, 255, 255})
{
    //1
    T_polygon({{373, 243},{362, 193},{370, 178},{446, 178},{453, 193},{441, 243}}, T_hubsColor);
    T_polygon({{381, 243},{378, 241},{406, 240},{433, 242},{424, 245}}, T_hubdarkColor, 0, -5);
    //windows
    T_polygon({{374, 226},{374, 211},{393, 207},{393, 223}}, T_hubdoorsColor);
    T_polygon({{420, 221},{420, 205},{439, 210},{439, 227}}, T_hubdoorsColor);
    T_polygon({{363, 193},{364, 186},{452, 186},{452, 193}}, T_hubdarkColor);

    //ladder
    T_polygon({{397, 199},{397, 167},{401, 167},{401, 199}}, T_ladderColor);
    T_polygon({{397, 199},{397, 167},{401, 167},{401, 199}}, T_ladderColor, 20, 0);

    T_polygon({{399, 201},{399, 196},{417, 196},{417, 201}}, T_ladderColor);
    T_polygon({{399, 201},{399, 196},{417, 196},{417, 201}}, T_ladderColor, 0, -10);
    T_polygon({{399, 201},{399, 196},{417, 196},{417, 201}}, T_ladderColor, 0, -20);

    //lines
    T_linestrip({{364, 202},{399, 202}}, T_ladderColor, 0, -2);
    T_linestrip({{408, 236},{408, 212}}, T_ladderColor);
    T_linestrip({{364, 202},{399, 202}}, T_ladderColor, 53, -2);



    //2
    T_polygon({{373, 243},{362, 193},{370, 178},{446, 178},{453, 193},{441, 243}}, T_hubsColor, 120, 70);
    T_polygon({{381, 243},{378, 241},{406, 240},{433, 242},{424, 245}}, T_hubdarkColor, 120, 65);
    //windows
    T_polygon({{374, 226},{374, 211},{393, 207},{393, 223}}, T_hubdoorsColor, 120, 70);
    T_polygon({{420, 221},{420, 205},{439, 210},{439, 227}}, T_hubdoorsColor, 120, 70);
    T_polygon({{363, 193},{364, 186},{452, 186},{452, 193}}, T_hubdarkColor, 120, 70);

    //ladder
    T_polygon({{397, 199},{397, 167},{401, 167},{401, 199}}, T_ladderColor, 120, 70);
    T_polygon({{397, 199},{397, 167},{401, 167},{401, 199}}, T_ladderColor, 140, 70);

    T_polygon({{399, 201},{399, 196},{417, 196},{417, 201}}, T_ladderColor, 120, 70);
    T_polygon({{399, 201},{399, 196},{417, 196},{417, 201}}, T_ladderColor, 120, 60);
    T_polygon({{399, 201},{399, 196},{417, 196},{417, 201}}, T_ladderColor, 120, 50);

    //lines
    T_linestrip({{364, 202},{399, 202}}, T_ladderColor, 120, 68);
    T_linestrip({{408, 236},{408, 212}}, T_ladderColor, 120, 70);
    T_linestrip({{364, 202},{399, 202}}, T_ladderColor, 173, 68);


    //3
    T_polygon({{373, 243},{362, 193},{370, 178},{446, 178},{453, 193},{441, 243}}, T_hubsColor, 1420, 300);
    T_polygon({{381, 243},{378, 241},{406, 240},{433, 242},{424, 245}}, T_hubdarkColor, 1420, 295);
    //windows
    T_polygon({{374, 226},{374, 211},{393, 207},{393, 223}}, T_hubdoorsColor, 1420, 300);
    T_polygon({{420, 221},{420, 205},{439, 210},{439, 227}}, T_hubdoorsColor, 1420, 300);
    T_polygon({{363, 193},{364, 186},{452, 186},{452, 193}}, T_hubdarkColor, 1420, 300);

    //ladder
    T_polygon({{397, 199},{397, 167},{401, 167},{401, 199}}, T_ladderColor, 1420, 300);
    T_polygon({{397, 199},{397, 167},{401, 167},{401, 199}}, T_ladderColor, 1440, 300);

    T_polygon({{399, 201},{399, 196},{417, 196},{417, 201}}, T_ladderColor, 1420, 300);
    T_polygon({{399, 201},{399, 196},{417, 196},{417, 201}}, T_ladderColor, 1420, 290);
    T_polygon({{399, 201},{399, 196},{417, 196},{417, 201}}, T_ladderColor, 1420, 280);

    //lines
    T_linestrip({{364, 202},{399, 202}}, T_ladderColor, 1420, 298);
    T_linestrip({{408, 236},{408, 212}}, T_ladderColor, 1420, 300);
    T_linestrip({{364, 202},{399, 202}}, T_ladderColor, 1473, 298);
}


void T_researchHub4(T_Color T_hubsColor = {37, 65, 102}, T_Color T_hubshadowColor = {33, 54, 82}, T_Color T_hubdoorsColor = {225, 203, 19}, T_Color T_hubdarkColor = {26, 43, 65}, T_Color T_ladderColor = {255, 255, 255}, T_Color T_hubgrillsColor = {0, 0, 0})
{
    T_polygon({{43, 30},{43, 10},{53, 10},{53, 30}}, T_ladderColor);
    T_polygon({{43, 30},{43, 10},{53, 10},{53, 30}}, T_ladderColor, 200);


    T_polygon({{150, 170},{115, 169},{30, 148},{23, 137},{23, 43},{35, 28},{76, 21},{199, 20},{254, 24},{268, 31},{272, 43},{272, 137},{268, 148},{187, 169}}, T_hubsColor);
    T_linestrip({{150, 170},{115, 169},{30, 148},{23, 137},{23, 43},{35, 28},{76, 21},{199, 20},{254, 24},{268, 31},{272, 43},{272, 137},{268, 148},{187, 169}}, T_hubdarkColor);
    T_polygon({{150, 170},{110, 169},{43, 152},{100, 142},{151, 139},{196, 143},{254, 151},{186, 169}}, T_hubdarkColor, 0, -10);

    T_polygon({{267, 123},{267, 46},{478, 46},{487, 55},{493, 69},{493, 100},{487, 120},{478, 123}}, T_hubsColor);

    T_polygon({{292, 50},{301, 29},{310, 29},{300, 50}}, T_ladderColor);
    T_polygon({{292, 50},{301, 29},{310, 29},{300, 50}}, T_ladderColor, 150);

    T_polygon({{36, 85},{36, 60},{47, 60},{47, 85}}, T_hubdoorsColor);

    T_polygon({{101, 108},{101, 58},{110, 58},{110, 108}}, T_hubdarkColor);
    T_polygon({{101, 108},{101, 58},{110, 58},{110, 108}}, T_hubdarkColor, 80);

    T_polygon({{223, 123},{222, 84},{255, 84},{258, 91},{258, 120},{256, 123}}, T_hubdarkColor);
    T_polygon({{223, 123},{222, 84},{255, 84},{258, 91},{258, 120},{256, 123}}, T_hubdarkColor, 0, -50);

    T_polygon({{228, 119},{228, 91},{258, 91},{258, 119}}, T_hubdoorsColor);
    T_polygon({{228, 119},{228, 91},{258, 91},{258, 119}}, T_hubdoorsColor, 0, -50);

    T_polygon({{331, 79},{324, 65},{346, 65}}, T_hubdoorsColor);
    T_polygon({{	333, 82},{349, 68},{356, 82}}, T_hubdoorsColor);
    T_polygon({{331, 79},{324, 65},{346, 65}}, T_hubdoorsColor, 100);
    T_polygon({{	333, 82},{349, 68},{356, 82}}, T_hubdoorsColor, 100);

    T_linestrip({{285, 80},{309, 80}}, T_hubgrillsColor);
    T_linestrip({{285, 80},{309, 80}}, T_hubgrillsColor, 0, -5);
    T_linestrip({{285, 80},{309, 80}}, T_hubgrillsColor, 0, -10);
    T_linestrip({{285, 80},{309, 80}}, T_hubgrillsColor, 0, -15);


    T_linestrip({{285, 80},{309, 80}}, T_hubgrillsColor, 100);
    T_linestrip({{285, 80},{309, 80}}, T_hubgrillsColor, 100, -5);
    T_linestrip({{285, 80},{309, 80}}, T_hubgrillsColor, 100, -10);
    T_linestrip({{285, 80},{309, 80}}, T_hubgrillsColor, 100, -15);

}



void T_tower(T_Color T_towerbodyColor = {255, 255, 255}, T_Color T_towershadowColor = {175,186,230}, T_Color T_towerglassColor = {73,189,231})
{
    T_polygon({{541, 453},{664, 453},{630, 533},{630, 624},{615, 639},{615, 838},{541, 838}}, T_towerbodyColor);
    T_polygon({{541, 453},{541, 515},{516, 515},{484, 488},{484, 453}}, T_towerbodyColor);
    T_polygon({{540, 809},{504, 726},{540, 705}}, T_towerbodyColor, 5, 0);
    T_polygon({{540, 843},{630, 867},{630, 930},{540, 890}}, T_towerbodyColor, 0, -5);


    // glass
    T_polygon({{564, 840},{564, 562},{595, 547},{614, 546},{614, 839},{586, 850}}, T_towerglassColor);



    //tower shadow
    T_polygon({{541, 453},{543, 498},{484, 474},{484, 453}}, T_towershadowColor);
    T_polygon({{541, 454},{569, 454},{569, 507},{559, 564},{559, 840},{541, 807}}, T_towershadowColor);
    T_polygon({{504, 726},{538, 705},{522, 701}}, T_towershadowColor, 5, 1);
    T_polygon({{538, 705},{522, 701},{522, 514},{538, 511}}, T_towershadowColor, 5, 1);
    T_polygon({{540, 843},{630, 867},{616, 843}}, T_towershadowColor, 0, -5);
    T_fullcircle(15, 545, 834, T_towershadowColor);


}

void T_towerbridge(T_Color T_bridgeColor = {255, 255, 255}, T_Color T_bridgelayersColor = {175,186,230}, T_Color T_bridgeboltsColor = {225, 203, 19}, T_Color T_bridgeshadowColor = {175,186,230})
{
    // main bridge
    T_polygon({{615, 620},{615, 590},{1920, 590},{1920, 620}}, T_bridgeColor);

    //upper lights
    T_polygon({{615, 620},{630, 610},{730, 610},{745, 620}}, T_bridgeshadowColor, 0, 0);
    T_polygon({{615, 620},{630, 610},{730, 610},{745, 620}}, T_bridgeshadowColor, 150, 0);
    T_polygon({{615, 620},{630, 610},{730, 610},{745, 620}}, T_bridgeshadowColor, 300, 0);
    T_polygon({{615, 620},{630, 610},{730, 610},{745, 620}}, T_bridgeshadowColor, 450, 0);
    T_polygon({{615, 620},{630, 610},{730, 610},{745, 620}}, T_bridgeshadowColor, 600, 0);
    T_polygon({{615, 620},{630, 610},{730, 610},{745, 620}}, T_bridgeshadowColor, 750, 0);
    T_polygon({{615, 620},{630, 610},{730, 610},{745, 620}}, T_bridgeshadowColor, 900, 0);
    T_polygon({{615, 620},{630, 610},{730, 610},{745, 620}}, T_bridgeshadowColor, 1050, 0);
    T_polygon({{615, 620},{630, 610},{730, 610},{745, 620}}, T_bridgeshadowColor, 1200, 0);

    // lower main bridge
    T_polygon({{615, 590},{615, 585},{1920, 585},{1920, 590}}, T_bridgelayersColor);

    // lower lights
    T_points3({{645, 585},{745, 585},{825, 585},{905, 585},{985, 585},{1065, 585},{1145, 585},{1225, 585},{1305, 585},{1385, 585},{1465, 585},{1545, 585},{1625, 585},{1705, 585},{1785, 585},{1865, 585}}, T_bridgeboltsColor);
}

void T_fixedrocket(T_Color T_rocketbodyColor = {147, 152, 158}, T_Color T_rocketshadeColor = {255, 255, 255}, T_Color T_rocketOutlines = {0,0,0})
{

    T_polygon({{529, 657},{508, 615},{508, 520},{551, 520},{551, 615}}, T_rocketbodyColor);
    T_polygon({{529, 650},{513, 615},{513, 515},{546, 515},{546, 615}}, T_rocketshadeColor);
    T_fullcircle(15, 528, 510, T_rocketbodyColor);
    T_polygon({{514, 604},{495, 580},{495, 505},{562, 505},{562, 580},{543, 604}}, T_rocketbodyColor);
    T_fullcircle(10, 528, 510, T_rocketshadeColor);
    T_polygon({{514, 604},{500, 575},{500, 510},{557, 510},{557, 575},{543, 604}}, T_rocketshadeColor);
    T_polygon({{510, 571},{480, 529},{480, 497},{580, 497},{580, 529},{545, 571}}, T_rocketbodyColor, 0, 20);
    T_polygon({{515, 571},{485, 529},{485, 497},{575, 497},{575, 529},{540, 571}}, T_rocketshadeColor, 0, 20);

    T_polygon({{498, 560},{498, 513},{503, 513},{504, 560}}, T_rocketbodyColor, 10, 3);
    T_polygon({{498, 560},{498, 513},{503, 513},{504, 560}}, T_rocketbodyColor, 45, 3);

    T_halfcircle(20, 530, 612, T_rocketbodyColor);
    T_halfcircle(20, 530, 605, T_rocketshadeColor);

    T_halfcircle(20, 530, 600, T_rocketbodyColor);
    T_halfcircle(20, 530, 594, T_rocketshadeColor);


}










//animations

void T_rocket(T_Color T_rocketbodyColor = {147, 152, 158}, T_Color T_rocketshadeColor = {255, 255, 255}, T_Color rocketouterlines = {147, 152, 158})
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0, T_moverocket, 0);

    T_polygon({{529, 657},{508, 615},{508, 520},{551, 520},{551, 615}}, T_rocketbodyColor);
    T_linestrip({{529, 657},{508, 615},{508, 520},{551, 520},{551, 615}}, rocketouterlines);
    T_polygon({{529, 650},{513, 615},{513, 515},{546, 515},{546, 615}}, T_rocketshadeColor);
    T_linestrip({{529, 650},{513, 615},{513, 515},{546, 515},{546, 615}}, rocketouterlines);
    T_fullcircle(15, 528, 510, T_rocketbodyColor);
    T_polygon({{514, 604},{495, 580},{495, 505},{562, 505},{562, 580},{543, 604}}, T_rocketbodyColor);
    T_fullcircle(10, 528, 510, T_rocketshadeColor);
    T_polygon({{514, 604},{500, 575},{500, 510},{557, 510},{557, 575},{543, 604}}, T_rocketshadeColor);
    T_polygon({{510, 571},{480, 529},{480, 497},{580, 497},{580, 529},{545, 571}}, T_rocketbodyColor, 0, 20);
    T_polygon({{515, 571},{485, 529},{485, 497},{575, 497},{575, 529},{540, 571}}, T_rocketshadeColor, 0, 20);

    T_polygon({{498, 560},{498, 513},{503, 513},{504, 560}}, T_rocketbodyColor, 10, 3);
    T_polygon({{498, 560},{498, 513},{503, 513},{504, 560}}, T_rocketbodyColor, 45, 3);

    T_halfcircle(20, 530, 612, T_rocketbodyColor);
    T_halfcircle(20, 530, 605, T_rocketshadeColor);

    T_halfcircle(20, 530, 600, T_rocketbodyColor);
    T_halfcircle(20, 530, 594, T_rocketshadeColor);

    glPopMatrix();
}

void T_externalplanet(T_Color T_planetColor = {219, 202, 135}, T_Color T_planetLayers = {24, 101, 70})
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(T_moveplanetX, T_moveplanetY, 0);

    T_fullcircle(80, 800, 1200, T_planetColor);
    //T_fullcircle(80, 1096, 740, sun);
    T_polygon({{1099, 697},{1102, 696},{1106, 699},{1107, 707},{1115, 717},{1109, 719},{1107, 725},{1094, 725}}, T_planetLayers, -296, 460);
    T_polygon({{1092, 725},{1090, 735},{1086, 734},{1080, 741},{1074, 739},{1066, 742},{1060, 737},{1060, 731}}, T_planetLayers, -296, 460);
    T_polygon({{1060, 730},{1055, 727},{1054, 719},{1058, 711},{1060, 707},{1068, 705},{1090, 706},{1107, 719},{1082, 734},{1064, 732}}, T_planetLayers, -296, 460);

    T_polygon({{1070, 708},{1070, 688},{1072, 686},{1070, 679},{1074, 675},{1073, 668},{1078, 657},{1088, 656},{1084, 662},{1086, 666},{1082, 668},{1082, 672},{1091, 676},{1097, 687}}, T_planetLayers, -296, 480);
    T_polygon({{1165, 765},{1156, 768},{1155, 773},{1143, 772},{1143, 771},{1134, 770},{1130, 768},{1131, 763},{1121, 757},{1124, 753},{1121, 743},{1130, 733},{1141, 732}}, T_planetLayers, -296, 460);

    T_polygon({{1155, 740},{1154, 726},{1161, 718},{1173, 720},{1175, 730},{1181, 741}}, T_planetLayers, -310, 460);

    T_polygon({{1156, 742},{1162, 735},{1173, 735},{1182, 739},{1181, 748},{1184, 750},{1178, 756}}, T_planetLayers, -310, 460);
    T_polygon({{1042, 764},{1056, 764},{1059, 761},{1061, 765},{1068, 770},{1069, 775},{1082, 785},{1088, 786},{1077, 793},{1069, 791}}, T_planetLayers, -296, 460);
    T_polygon({{1066, 791},{1064, 799},{1074, 807},{1068, 810},{1061, 815},{1056, 810},{1049, 809}}, T_planetLayers, -296, 450);
    T_polygon({{1049, 807},{1036, 801},{1033, 795},{1034, 785},{1046, 785},{1057, 779}}, T_planetLayers, -286, 450);
    T_polygon({{1049, 807},{1036, 801},{1033, 795},{1034, 785},{1046, 785},{1057, 779}}, T_planetLayers, -296, 420);
    T_polygon({{1049, 807},{1036, 801},{1033, 795},{1034, 785},{1046, 785},{1057, 779}}, T_planetLayers, -296, 430);

    glPopMatrix();
}

void T_rover(T_Color T_rovermetalColor = {94,97,103}, T_Color T_roverdarkmetalColor = {35,39,43}, T_Color T_roverwindowColor = {11,76,104}, T_Color T_roverlightsColor = {212,133,105}, T_Color T_roverwheelsColor = {138,138,138}, T_Color T_roverwheelscrewColor = {61,62,64}, T_Color T_roverlightmetalColor = {210,211,213}, T_Color T_roveroutlinesColor = {0, 0, 0})
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(T_moverover, 0, 0);

    //rover body
    T_polygon({{1281, 130},{1264, 115},{1259, 93},{1252, 86},{1242, 76},{1250, 60},{1397, 60},{1409, 73},{1409, 88},{1397, 116},{1377, 130}}, T_rovermetalColor, 200, 0);
    T_linestrip({{1281, 130},{1264, 115},{1259, 93},{1252, 86},{1242, 76},{1250, 60},{1397, 60},{1409, 73},{1409, 88},{1397, 116},{1377, 130}}, T_roveroutlinesColor, 200, 0);

    T_polygon({{1267, 117},{1245, 74},{1405, 74},{1405, 83},{1391, 117}}, T_roverlightmetalColor, 200, 0);
    T_linestrip({{1267, 117},{1245, 74},{1405, 74},{1405, 83},{1391, 117}}, T_roveroutlinesColor, 200, 0);

    T_polygon({{1250, 89},{1248, 86},{1450, 86},{1400, 89}}, T_roverdarkmetalColor, 200, 0);

    T_polygon({{1265, 67},{1265, 64},{1305, 64},{1305, 67}}, T_roverdarkmetalColor, 200, 0);
    T_polygon({{1265, 67},{1265, 64},{1305, 64},{1305, 67}}, T_roverdarkmetalColor, 270, 0);

    T_polygon({{1263, 66},{1263, 59},{1267, 59},{1267, 66}}, T_roverdarkmetalColor, 200, 0);
    T_polygon({{1263, 66},{1263, 59},{1267, 59},{1267, 66}}, T_roverdarkmetalColor, 240, 0);
    T_polygon({{1263, 66},{1263, 59},{1267, 59},{1267, 66}}, T_roverdarkmetalColor, 270, 0);
    T_polygon({{1263, 66},{1263, 59},{1267, 59},{1267, 66}}, T_roverdarkmetalColor, 310, 0);


    T_polygon({{1282, 128},{1267, 115},{1260, 93},{1322, 93},{1338, 128}}, T_roverwindowColor, 200, 0);

    T_polygon({{1341, 119},{1331, 95},{1365, 95}}, T_roverwindowColor, 200, 0);

    T_polygon({{1250, 84},{1244, 76},{1249, 76}}, T_roverlightsColor, 200, 0);

    // wheels
    T_fullcircle(15, 1265+200, 42, T_roverwheelsColor);
    T_fullcircleBorder(15, 1265+200, 42, T_roverwheelscrewColor);
    T_fullcircle(8, 1265+200, 42, T_roverwheelscrewColor);

    T_fullcircle(15, 1300+200, 42, T_roverwheelsColor);
    T_fullcircleBorder(15, 1300+200, 42, T_roverwheelscrewColor);
    T_fullcircle(8, 1300+200, 42, T_roverwheelscrewColor);

    T_fullcircle(15, 1335+200, 42, T_roverwheelsColor);
    T_fullcircleBorder(15, 1335+200, 42, T_roverwheelscrewColor);
    T_fullcircle(8, 1335+200, 42, T_roverwheelscrewColor);

    T_fullcircle(15, 1375+200, 42, T_roverwheelsColor);
    T_fullcircleBorder(15, 1375+200, 42, T_roverwheelscrewColor);
    T_fullcircle(8, 1375+200, 42, T_roverwheelscrewColor);

    T_polygon({{1386, 122},{1392, 124},{1403, 127},{1414, 129},{1419, 123},{1419, 116},{1419, 109},{1418, 100},{1408, 102},{1398, 103}}, T_rovermetalColor, 200);
    T_polygon({{1386, 122},{1392, 124},{1403, 127},{1414, 129},{1419, 123},{1419, 116},{1419, 109},{1418, 100},{1408, 102},{1398, 103}}, T_rovermetalColor, 200, -5);

    glPopMatrix();
}

void T_boat1(T_Color T_boatColor = {255, 255, 255}, T_Color T_boatbottomColor = {39,30,73}, T_Color T_boatwindowColor = {107,111,116})
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(T_moveboatX, T_moveboatY, 0);
    T_polygon({{1679, 268},{1719, 237},{1753, 232},{1837, 229},{1858, 248},{1847, 257},{1760, 271}}, T_boatColor, 300, -60);
    T_polygon({{1807, 282},{1805, 286},{1828, 288},{1820, 290},{1784, 291}}, T_boatColor, 300, -65);
    T_polygon({{1679, 268},{1719, 237},{1753, 232},{1837, 229},{1854, 245},{1796, 251},{1755, 248}}, T_boatbottomColor, 300, -60);
    T_polygon({{1822, 261},{1803, 286},{1751, 291},{1729, 271},{1764, 271}}, T_boatColor, 300, -60);
    T_polygon({{1751, 289},{1735, 273},{1762, 272},{1766, 288}}, T_boatwindowColor, 300, -60);
    T_polygon({{1772, 287},{1766, 273},{1786, 269},{1787, 285}}, T_boatwindowColor, 300, -60);
    T_polygon({{1790, 286},{1790, 267},{1816, 262},{1801, 285}}, T_boatwindowColor, 300, -60);
    T_linestrip({{1681, 265},{1732, 264},{1780, 258},{1851, 246}}, T_boatbottomColor, 300, -57);

    glPopMatrix();
}


void T_spaceship(T_Color T_spaceshipbodyColor = {226,225,231}, T_Color T_spaceshipwindowColor = {50,50,48}, T_Color T_spaceshiplayersColor = {50,50,48}, T_Color T_spaceshipoutlinesColor = {0, 0, 0})
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(T_movespaceshipX, 0, 0);

    T_polygon({{1629, 985},{1604, 968},{1632, 954},{1695, 954},{1732, 967},{1745, 987},{1723, 987},{1643, 987}}, T_spaceshipbodyColor);
    T_polygon({{1673, 1004},{1630, 975},{1691, 975},{1723, 1004}}, T_spaceshipbodyColor);
    T_polygon({{1723, 1001},{1692, 973},{1692, 945},{1722, 983}}, T_spaceshipbodyColor, 0, 5);
    T_polygon({{1687, 1011},{1660, 993},{1683, 993},{1709, 1011}}, T_spaceshipbodyColor);
    T_polygon({{1683, 992},{1689, 983},{1714, 1002},{1708, 1010}}, T_spaceshipbodyColor);
    T_polygon({{1628, 974},{1628, 947},{1691, 947},{1691, 974}}, T_spaceshipbodyColor);

    T_linestrip({{1723, 1001},{1692, 973},{1692, 945},{1722, 983}}, T_spaceshipoutlinesColor, 0, 3);
    T_linestrip({{1687, 1011},{1660, 993},{1683, 993},{1709, 1011}}, T_spaceshipoutlinesColor);
    T_linestrip({{1683, 992},{1689, 983},{1714, 1002},{1708, 1010}}, T_spaceshipoutlinesColor);
    T_linestrip({{1628, 974},{1628, 947},{1691, 947},{1691, 974}}, T_spaceshipoutlinesColor);

    T_polygon({{1637, 965},{1626, 935},{1626, 927},{1634, 924},{1643, 926},{1683, 945},{1682, 965},{1655, 966}}, T_spaceshipbodyColor);
    T_polygon({{1749, 994},{1735, 971},{1762, 970},{1771, 986}}, T_spaceshipbodyColor, -1);
    T_polygon({{1749, 994},{1735, 971},{1762, 970},{1771, 986}}, T_spaceshipbodyColor, -10);
    T_polygon({{1610, 996},{1581, 977},{1603, 969},{1629, 984}}, T_spaceshipbodyColor, 1);

    T_polygon({{1638, 964},{1629, 936},{1634, 937},{1649, 964}}, T_spaceshipwindowColor);
    T_polygon({{1661, 964},{1638, 937},{1643, 934},{1676, 963}}, T_spaceshipwindowColor);
    T_polygon({{1634, 935},{1628, 932},{1627, 929},{1634, 926},{1641, 928},{1641, 932}}, T_spaceshipwindowColor);
    T_polygon({{1681, 959},{1651, 933},{1680, 948}}, T_spaceshipwindowColor);
    T_polygon({{1667, 991},{1659, 991},{1655, 985},{1665, 985}}, T_spaceshipwindowColor);
    T_polygon({{1672, 991},{1669, 985},{1683, 985},{1680, 991}}, T_spaceshipwindowColor);
    T_polygon({{1707, 1008},{1687, 991},{1689, 985},{1711, 1003}}, T_spaceshipwindowColor);
    T_polygon({{1626, 965},{1608, 965},{1626, 959}}, T_spaceshipwindowColor, 2);
    T_polygon({{1703, 966},{1703, 959},{1727, 967}}, T_spaceshipwindowColor, -2);

    T_fullcircle(15, 1745, 963, T_spaceshipbodyColor);
    T_fullcircle(10, 1745, 963, T_spaceshiplayersColor);
    T_fullcircleBorder(15, 1745, 963, T_spaceshipwindowColor);
    T_fullcircle(15, 1591, 970, T_spaceshipbodyColor);
    T_fullcircle(10, 1591, 970, T_spaceshiplayersColor);
    T_fullcircleBorder(15, 1591, 970, T_spaceshipwindowColor);

    T_linestrip({{1695, 1011},{1670, 993},{1666, 982},{1657, 975}}, T_spaceshiplayersColor);
    T_linestrip({{1633, 976},{1640, 979},{1687, 977},{1691, 973}}, T_spaceshiplayersColor, 0, -2);
    T_linestrip({{1715, 1000},{1695, 983}}, T_spaceshiplayersColor);
    T_linestrip({{1724, 987},{1706, 968}}, T_spaceshiplayersColor);
    T_linestrip({{1622, 989},{1606, 980}}, T_spaceshiplayersColor);
    T_linestrip({{1624, 985},{1607, 975}}, T_spaceshiplayersColor);
    T_linestrip({{1767, 988},{1762, 977}}, T_spaceshiplayersColor);
    T_linestrip({{1766, 989},{1760, 978}}, T_spaceshiplayersColor, -2);
    T_linestrip({{1718, 997},{1718, 992},{1704, 979}}, T_spaceshiplayersColor);

    glPopMatrix();
}


void idle()
{
    if(P1[0].first < 615) f1 = -1;
    if(P1[0].first > 665) f1 = 1;
    if(P1[1].first < 600) f2 = 1;
    if(P1[1].first > 680)  f2 = -1;
    P1[0].first -= 0.5 * f1;
    P2[0].first -= 0.5 * f1;
    P1[1].first += 0.5 * f2;
    P2[1].first += 0.5 * f2;

    glutPostRedisplay();
}


void T_riverflow(T_Color T_rivershade1Color = {61, 109, 186}, T_Color T_rivershade2Color = {54,102,192}, T_Color T_rivershade3Color = {33, 59, 122}, T_Color T_rivershade4Color = {110,161,233})
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(T_movewatercurrentX, 0, 0);


    // manual shades
    //type 1
    T_polygon({{1234, 403},{1402, 397},{1611, 413},{1414, 381}}, T_rivershade1Color, -50);
    T_polygon({{1234, 403},{1402, 397},{1611, 413},{1414, 381}}, T_rivershade1Color, -150, 50);
    T_polygon({{1234, 403},{1402, 397},{1611, 413},{1414, 381}}, T_rivershade1Color, -270, 50);
    //type 2
    T_polygon({{1328, 326},{1593, 337},{1897, 319},{1407, 307}}, T_rivershade1Color);
    T_polygon({{1328, 326},{1593, 337},{1897, 319},{1407, 307}}, T_rivershade1Color, -750);

    //type 3
    T_polygon({{568, 401},{829, 395},{1086, 410},{790, 374}}, T_rivershade2Color);
    T_polygon({{568, 401},{829, 395},{1086, 410},{790, 374}}, T_rivershade2Color, -700, -50);
    T_polygon({{568, 401},{829, 395},{1086, 410},{790, 374}}, T_rivershade2Color, 100, -100);
    T_polygon({{568, 401},{829, 395},{1086, 410},{790, 374}}, T_rivershade2Color, -1200, -100);

    //type 4
    T_polygon({{633, 399},{895, 433},{1216, 417},{778, 399}}, T_rivershade2Color, -500, 20);
    T_polygon({{633, 399},{895, 433},{1216, 417},{778, 399}}, T_rivershade2Color, 200, -180);
    T_polygon({{633, 399},{895, 433},{1216, 417},{778, 399}}, T_rivershade2Color, 800, -200);
    T_polygon({{633, 399},{895, 433},{1216, 417},{778, 399}}, T_rivershade2Color, -800, -150);
    T_polygon({{633, 399},{895, 433},{1216, 417},{778, 399}}, T_rivershade2Color, -1200, -150);
    T_polygon({{633, 399},{895, 433},{1216, 417},{778, 399}}, T_rivershade2Color, -1200, -40);

    //type 5
    T_polygon({{1248, 397},{1446, 388},{1676, 400},{1425, 399}}, T_rivershade4Color, 0, 50);
    T_polygon({{1248, 397},{1446, 388},{1676, 400},{1425, 399}}, T_rivershade4Color, -700, 50);
    T_polygon({{1248, 397},{1446, 388},{1676, 400},{1425, 399}}, T_rivershade4Color, -1200, 20);
    T_polygon({{1248, 397},{1446, 388},{1676, 400},{1425, 399}}, T_rivershade4Color, -500, -10);



    glPopMatrix();

}

void T_stars(T_Color T_starsColor = {255, 255, 255})
{
    T_points2({{1174, 970},{1348, 989},{1336, 945},{1435, 921},{1582, 927}}, T_starsColor);
    T_points2({{1174, 970},{1348, 989},{1336, 945},{1435, 921},{1582, 927}}, T_starsColor, 400);
    T_points2({{1174, 970},{1348, 989},{1336, 945},{1435, 921},{1582, 927}}, T_starsColor, -200);
    T_points2({{1174, 970},{1348, 989},{1336, 945},{1435, 921},{1582, 927}}, T_starsColor, -600, -100);
    T_points2({{1174, 970},{1348, 989},{1336, 945},{1435, 921},{1582, 927}}, T_starsColor, -600, -150);
    T_points2({{1174, 970},{1348, 989},{1336, 945},{1435, 921},{1582, 927}}, T_starsColor, -1000, -150);

    T_points1({{256, 1004},{349, 962},{279, 953},{283, 872},{406, 936},{406, 857},{370, 814},{341, 723},{321, 757},{584, 1021},{514, 983},{618, 970},{735, 962},{828, 893},{784, 1011},{915, 989},{932, 874},{835, 727},{780, 791},{854, 802},{990, 712},{918, 650},{765, 586},{1246, 561},{1374, 753},{1212, 893},{1306, 1030},{1369, 970},{1476, 913},{1480, 849},{1325, 870},{1240, 774},{1077, 1026},{1043, 942},{1204, 983},{1792, 761},{1779, 866},{1679, 810},{1603, 868},{1616, 893},{1537, 759},{1607, 744},{1514, 684},{1467, 537},{1376, 631},{1276, 667},{1249, 603},{1344, 535},{1823, 1011},{1872, 927},{1887, 1028},{1450, 1075},}, T_starsColor, -150);
}



void T_radar(T_Color T_radarbodyColor = {178,15,17}, T_Color T_radarColor = {0, 255, 0}, T_Color T_radaroutlinesColor = {37,31,67})
{

    T_linestrip({{281, 657},{271, 648},{282, 636},{269, 627},{283, 615},{268, 606}}, T_radarColor);
    T_linestrip({{271, 655},{281, 648},{270, 638},{282, 626},{269, 615},{284, 606}}, T_radarColor);
    T_linestrip({{271, 575},{280, 575},{271, 565},{281, 564},{272, 555},{281, 555},{272, 545},{281, 544},{272, 535},{280, 534},{271, 524},{280, 524},{271, 514},{281, 514},{271, 506}}, T_radarColor, 0, 20);
    T_linestrip({{281, 575},{271, 575},{281, 565},{271, 565},{280, 555},{271, 555},{280, 545},{271, 545},{280, 535},{271, 535},{280, 525},{271, 525},{280, 514},{271, 514},{280, 506},}, T_radarColor, 0, 20);
    T_linestrip({{267, 581},{271, 575},{265, 575},{270, 565},{264, 564},{271, 555},{263, 555},{271, 544},{261, 544},{271, 534},{261, 535},{270, 524},{259, 525},{270, 515},{258, 515},{265, 508}}, T_radarColor, 0, 20);
    T_linestrip({{256, 504},{271, 514},{259, 515},{269, 523},{259, 524},{269, 533},{260, 534},{270, 545},{261, 545},{272, 554},{263, 554},{271, 564},{264, 564},{271, 574},{265, 574},{272, 579}}, T_radarColor, 0, 20);
    T_linestrip({{282, 581},{287, 575},{281, 575},{288, 565},{282, 565},{289, 555},{281, 555},{290, 546},{282, 545},{291, 535},{282, 535},{293, 525},{281, 525},{294, 515},{282, 515},{296, 505}}, T_radarColor, 0, 20);
    T_linestrip({{282, 580},{287, 575},{281, 565},{288, 565},{283, 555},{290, 555},{282, 545},{290, 545},{282, 535},{292, 535},{282, 525},{294, 525},{283, 514},{295, 514},{281, 506}}, T_radarColor, 0, 20);

    T_polygon({{264, 490},{264, 450},{288, 450},{288, 490}}, T_radarbodyColor, 0, 30);
    T_linestrip({{264, 490},{264, 450},{288, 450},{288, 490}}, T_radaroutlinesColor, 0, 30);
    T_polygon({{276, 699},{274, 661},{278, 661}}, T_radarbodyColor);
    T_linestrip({{276, 699},{274, 661},{278, 661}}, T_radaroutlinesColor);
    T_polygon({{275, 656},{275, 607},{277, 607},{277, 656}}, T_radarbodyColor);
    T_linestrip({{275, 656},{275, 607},{277, 607},{277, 656}}, T_radaroutlinesColor);
    T_polygon({{257, 602},{262, 593},{265, 592},{286, 592},{290, 593},{294, 604},{288, 607},{266, 607}}, T_radarbodyColor);
    T_linestrip({{257, 602},{262, 593},{265, 592},{286, 592},{290, 593},{294, 604},{288, 607},{266, 607}}, T_radaroutlinesColor);
    T_polygon({{244, 506},{248, 490},{303, 490},{308, 507},{301, 508},{251, 508}}, T_radarbodyColor, 0, 20);
    T_linestrip({{244, 506},{248, 490},{303, 490},{308, 507},{301, 508},{251, 508}}, T_radaroutlinesColor, 0, 20);

    T_polygon({{268, 660},{268, 657},{282, 657},{282, 660}}, T_radarbodyColor);
    T_linestrip({{268, 660},{268, 657},{282, 657},{282, 660}}, T_radaroutlinesColor);



    T_linestrip({{281, 657},{271, 648},{282, 636},{269, 627},{283, 615},{268, 606}}, T_radarColor, 1200);
    T_linestrip({{271, 655},{281, 648},{270, 638},{282, 626},{269, 615},{284, 606}}, T_radarColor, 1200);
    T_linestrip({{271, 575},{280, 575},{271, 565},{281, 564},{272, 555},{281, 555},{272, 545},{281, 544},{272, 535},{280, 534},{271, 524},{280, 524},{271, 514},{281, 514},{271, 506}}, T_radarColor, 1200, 20);
    T_linestrip({{281, 575},{271, 575},{281, 565},{271, 565},{280, 555},{271, 555},{280, 545},{271, 545},{280, 535},{271, 535},{280, 525},{271, 525},{280, 514},{271, 514},{280, 506},}, T_radarColor, 1200, 20);
    T_linestrip({{267, 581},{271, 575},{265, 575},{270, 565},{264, 564},{271, 555},{263, 555},{271, 544},{261, 544},{271, 534},{261, 535},{270, 524},{259, 525},{270, 515},{258, 515},{265, 508}}, T_radarColor, 1200, 20);
    T_linestrip({{256, 504},{271, 514},{259, 515},{269, 523},{259, 524},{269, 533},{260, 534},{270, 545},{261, 545},{272, 554},{263, 554},{271, 564},{264, 564},{271, 574},{265, 574},{272, 579}}, T_radarColor, 1200, 20);
    T_linestrip({{282, 581},{287, 575},{281, 575},{288, 565},{282, 565},{289, 555},{281, 555},{290, 546},{282, 545},{291, 535},{282, 535},{293, 525},{281, 525},{294, 515},{282, 515},{296, 505}}, T_radarColor, 1200, 20);
    T_linestrip({{282, 580},{287, 575},{281, 565},{288, 565},{283, 555},{290, 555},{282, 545},{290, 545},{282, 535},{292, 535},{282, 525},{294, 525},{283, 514},{295, 514},{281, 506}}, T_radarColor, 1200, 20);

    T_polygon({{264, 490},{264, 450},{288, 450},{288, 490}}, T_radarbodyColor, 1200, 30);
    T_linestrip({{264, 490},{264, 450},{288, 450},{288, 490}}, T_radaroutlinesColor, 1200, 30);
    T_polygon({{276, 699},{274, 661},{278, 661}}, T_radarbodyColor, 1200);
    T_linestrip({{276, 699},{274, 661},{278, 661}}, T_radaroutlinesColor, 1200);
    T_polygon({{275, 656},{275, 607},{277, 607},{277, 656}}, T_radarbodyColor, 1200);
    T_linestrip({{275, 656},{275, 607},{277, 607},{277, 656}}, T_radaroutlinesColor, 1200);
    T_polygon({{257, 602},{262, 593},{265, 592},{286, 592},{290, 593},{294, 604},{288, 607},{266, 607}}, T_radarbodyColor, 1200);
    T_linestrip({{257, 602},{262, 593},{265, 592},{286, 592},{290, 593},{294, 604},{288, 607},{266, 607}}, T_radaroutlinesColor, 1200);
    T_polygon({{244, 506},{248, 490},{303, 490},{308, 507},{301, 508},{251, 508}}, T_radarbodyColor, 1200, 20);
    T_linestrip({{244, 506},{248, 490},{303, 490},{308, 507},{301, 508},{251, 508}}, T_radaroutlinesColor, 1200, 20);

    T_polygon({{268, 660},{268, 657},{282, 657},{282, 660}}, T_radarbodyColor, 1200, 0);
    T_linestrip({{268, 660},{268, 657},{282, 657},{282, 660}}, T_radaroutlinesColor, 1200, 0);
}


void T_transmitter(T_Color T_transmitterbodyColor = {171, 178, 185}, T_Color T_transmitteroutlinesColor = {0, 0, 0})
{
    T_polygon({{771, 243},{771, 229},{830, 229},{830, 243}}, T_transmitterbodyColor);
    T_linestrip({{771, 243},{771, 229},{830, 229},{830, 243}}, T_transmitteroutlinesColor);

    T_polygon({{761, 252},{761, 247},{773, 239},{828, 239},{839, 247},{839, 252}}, T_transmitterbodyColor);
    T_linestrip({{761, 252},{761, 247},{773, 239},{828, 239},{839, 247},{839, 252}}, T_transmitteroutlinesColor);

    T_polygon({{795, 347},{795, 265},{805, 265},{805, 347}}, T_transmitterbodyColor);
    T_linestrip({{795, 347},{795, 265},{805, 265},{805, 347}}, T_transmitteroutlinesColor);

    T_polygon({{797, 281},{792, 275},{791, 250},{810, 250},{809, 275},{803, 281}}, T_transmitterbodyColor);
    T_linestrip({{797, 281},{792, 275},{791, 250},{810, 250},{809, 275},{803, 281}}, T_transmitteroutlinesColor);

    T_polygon({{791, 362},{791, 348},{793, 344},{793, 327},{808, 327},{808, 344},{810, 348},{810, 362}}, T_transmitterbodyColor);
    T_linestrip({{791, 362},{791, 348},{793, 344},{793, 327},{808, 327},{808, 344},{810, 348},{810, 362}}, T_transmitteroutlinesColor);

    T_polygon({{784, 381},{784, 308},{786, 298},{788, 308},{788, 381}}, T_transmitterbodyColor);
    T_linestrip({{784, 381},{784, 308},{786, 298},{788, 308},{788, 381}}, T_transmitteroutlinesColor);
    T_polygon({{784, 381},{784, 308},{786, 298},{788, 308},{788, 381}}, T_transmitterbodyColor, 30);
    T_linestrip({{784, 381},{784, 308},{786, 298},{788, 308},{788, 381}}, T_transmitteroutlinesColor, 30);

}


void T_transmittersignal(T_Color T_transmittersignalColor = {255, 255, 255}, T_Color T_transmitantennaColor = {255, 0, 0}, T_Color T_steelbodyColor = {166, 172, 175})
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(800, 382, 0);
    glRotatef(T_blinkAngle, 0, 0, 1);
    glTranslatef(-800, -382, 0);

    T_halfcircle(50, 800, 382);
    T_halfcircleBorder(50, 800, 382);
    T_polygon({{798, 379},{798, 345},{801, 345},{801, 379}}, T_transmitantennaColor);
    T_fullcircle(10, 801, 380);

    //lines
    T_linestrip({{752, 380},{800, 345}}, T_transmitantennaColor);
    T_linestrip({{782, 381},{798, 345}}, T_transmitantennaColor);
    T_linestrip({{848, 382},{805, 345}}, T_transmitantennaColor, -2);
    T_linestrip({{823, 382},{803, 345}}, T_transmitantennaColor, -3);

    T_linestrip({{797, 349},{806, 345},{797, 341},{806, 336},{797, 332},{806, 328},{801, 326}}, T_transmitantennaColor);
    T_linestrip({{805, 348},{797, 343},{806, 339},{797, 335},{805, 331},{797, 328},{801, 325}}, T_transmitantennaColor);
    T_polygon({{728, 387},{750, 392},{776, 396},{801, 396},{826, 396},{852, 394},{871, 389}}, T_steelbodyColor, 0, -10);

    T_linestrip({{751, 395},{789, 402},{822, 402},{849, 397}}, T_steelbodyColor, 0, -8);
    T_linestrip({{751, 395},{789, 402},{822, 402},{849, 397}}, T_steelbodyColor, 0, -10);
    T_linestrip({{761, 402},{789, 406},{817, 405},{841, 403}}, T_steelbodyColor);
    T_linestrip({{761, 402},{789, 406},{817, 405},{841, 403}}, T_steelbodyColor, 0, 10);


    glPopMatrix();

}


void T_walle(T_Color T_wallebodyColor = {168,159,150}, T_Color T_walleshadowColor = {82,63,68}, T_Color T_solarpanelColor = {130,167,210}, T_Color T_walleoutlinesColor = {0, 0, 0})
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(T_movewalleX, 0, 0);
    glTranslatef(-1200, 0, 0);
    T_polygon({{1011, 552},{1009, 549},{1009, 537},{1011, 534},{1121, 534},{1117, 552},{1111, 553}}, T_wallebodyColor, 0, -25);
    T_linestrip({{1011, 552},{1009, 549},{1009, 537},{1011, 534},{1121, 534},{1117, 552},{1111, 553}}, T_walleshadowColor, 0, -25);

    T_polygon({{1056, 572},{1055, 554},{1050, 554},{1050, 550},{1080, 550},{1080, 554},{1077, 554},{1070, 572}}, T_walleshadowColor, 0, -25);
    T_linestrip({{1056, 572},{1055, 554},{1050, 554},{1050, 550},{1080, 550},{1080, 554},{1077, 554},{1070, 572}}, T_walleoutlinesColor, 0, -25);

    T_polygon({{1058, 593},{1058, 587},{1059, 574},{1064, 574},{1064, 587},{1064, 593}}, T_walleshadowColor, 0, -30);

    T_polygon({{1046, 578},{1044, 553},{1049, 553}}, T_walleshadowColor, -2, -25);
    T_polygon({{1046, 578},{1044, 553},{1049, 553}}, T_walleshadowColor, -30, -25);

    T_polygon({{1018, 580},{998, 554},{1034, 554},{1054, 580}}, T_solarpanelColor, 0, -25);
    T_linestrip({{1018, 580},{998, 554},{1034, 554},{1054, 580}}, T_walleshadowColor, 0, -25);

    T_polygon({{1088, 575},{1088, 553},{1112, 553}}, T_wallebodyColor, 0, -25);
    T_linestrip({{1088, 575},{1088, 553},{1112, 553}}, T_walleshadowColor, 0, -25);
    T_polygon({{1087, 575},{1088, 570},{1110, 570},{1109, 575}}, T_wallebodyColor, 0, -25);
    T_linestrip({{1087, 575},{1088, 570},{1110, 570},{1109, 575}}, T_walleshadowColor, 0, -25);

    T_polygon({{1101, 582},{1100, 573},{1101, 566},{1139, 566},{1142, 573},{1138, 582}}, T_walleshadowColor, 0, -25);

    T_polygon({{1106, 550},{1109, 536},{1119, 536},{1116, 550}}, T_walleshadowColor, 0, -25);

    T_linestrip({{999, 520},{1024, 519},{1027, 532},{1046, 532},{1052, 519},{1077, 519},{1083, 531},{1102, 532},{1106, 519},{1118, 519}}, T_walleshadowColor, 0, -25);

    T_linestrip({{1025, 519},{1048, 519},{1054, 531},{1076, 531},{1081, 519},{1095, 519}}, T_walleshadowColor, 0, -25);

    T_fullcircle(5, 1088, 548, T_walleshadowColor);
    T_fullcircle(2, 1088, 548, T_wallebodyColor);

    // hook
    T_polygon({{1111, 549},{1114, 538},{1120, 540},{1142, 538},{1144, 542}}, T_wallebodyColor, 0, -25);

    // joint bolts
    T_fullcircle(5, 1146, 514, T_wallebodyColor);

    T_polygon({{1150, 538},{1160, 564},{1147, 542}}, T_wallebodyColor, 0, -25);

    // puller
    T_fullcircle(10, 1163, 539, T_wallebodyColor);
    T_fullcircle(7, 1167, 539, T_walleshadowColor);


    //tires
    T_fullcircle(13, 1006, 490, T_walleshadowColor);
    T_fullcircleBorder(13, 1006, 490, T_wallebodyColor);
    T_fullcircle(8, 1006, 490, T_wallebodyColor);
    T_fullcircle(13, 1035, 490, T_walleshadowColor);
    T_fullcircleBorder(13, 1035, 490, T_wallebodyColor);
    T_fullcircle(8, 1035, 490, T_wallebodyColor);
    T_fullcircle(13, 1064, 490, T_walleshadowColor);
    T_fullcircleBorder(13, 1064, 490, T_wallebodyColor);
    T_fullcircle(8, 1064, 490, T_wallebodyColor);
    T_fullcircle(13, 1093, 490, T_walleshadowColor);
    T_fullcircleBorder(13, 1093, 490, T_wallebodyColor);
    T_fullcircle(8, 1093, 490, T_wallebodyColor);
    T_fullcircle(13, 1122, 490, T_walleshadowColor);
    T_fullcircleBorder(13, 1122, 490, T_wallebodyColor);
    T_fullcircle(8, 1122, 490, T_wallebodyColor);

    //eyes
    T_blinkingWalleEyes(1116, 548, T_wallebodyColor);
    T_blinkingWalleEyes(1131, 548, T_wallebodyColor);

    //solar panel
    T_linestrip({{1023, 580},{1006, 555}}, T_walleoutlinesColor, 0, -26);
    T_linestrip({{1023, 580},{1006, 555}}, T_walleoutlinesColor, 10, -26);
    T_linestrip({{1023, 580},{1006, 555}}, T_walleoutlinesColor, 20, -26);
    T_linestrip({{1023, 580},{1006, 555}}, T_walleoutlinesColor, 30, -26);

    T_linestrip({{1014, 575},{1049, 575}}, T_walleoutlinesColor, 0, -26);
    T_linestrip({{1014, 575},{1049, 575}}, T_walleoutlinesColor, -8, -34);
    T_linestrip({{1014, 575},{1049, 575}}, T_walleoutlinesColor, -16, -44);

    glPopMatrix();

}


void T_display() {
	glClearColor(1, 1, 1, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


    T_sky();
    T_stars();

    T_externalplanet();
    T_towerbridge();
    T_tower();

    T_rocket();

	T_river();
	T_riverflow();
	T_boat1();

    T_land();
    T_darkrocks();
    T_lightrocks();

    T_Fire(P1, P2);
    idle();
    T_specialstoneholder();



    T_walle();
    T_researchHub2();
    T_researchHub1();

    T_researchHub3();

    T_rover();
    T_researchHub4();


    T_spaceship();
    T_radar();
    T_transmitter();
    T_transmittersignal();
    T_blinkingCircle(275, 706);
    T_blinkingCircle(1476, 706);


	glFlush();  // Render now

	glutSwapBuffers();
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(1920, 1080);


	glutInitWindowPosition(0, 0);
	glutCreateWindow("Lunaris");

    //this line must be below of glutCreateWindow();
    gluOrtho2D(0, 1920, 0, 1080);
	glutDisplayFunc(T_display);

	glutTimerFunc(20, T_animateRocket, 0);
	glutTimerFunc(20, T_animatePlanets, 0);
	glutTimerFunc(20, T_animateRoverLeft, 0);
	glutTimerFunc(20, T_animateBoatLeft, 0);
	glutTimerFunc(20, T_animateSpaceshipLeft, 0);
	glutTimerFunc(20, T_animateWaterCurrentRight, 0);
	glutTimerFunc(20, T_animateBlinkCircle, 0);
	glutTimerFunc(20, T_animateWalleRight, 0);
	glutMainLoop();
	return 0;
}
