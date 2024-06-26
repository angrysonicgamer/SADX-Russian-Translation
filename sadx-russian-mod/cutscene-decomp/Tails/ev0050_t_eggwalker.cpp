#include "stdafx.h"

#include "SADXModLoader.h"
#include "SADXEventFunctions.h"
#include "SADXEventVariables.h"

PVMEntry texTbl_ev0050[] = {
	(char*)("EV_EGGMOBLE0"), &EV_EGGMOBLE0_TEXLIST,
	(char*)("EV_EGGMOBLE2"), &EV_EGGMOBLE2_TEXLIST,
	(char*)("EV_EGGMAN_BODY"), & EV_EGGMAN_BODY_TEXLIST,
	0
};

void ev0050_t_eggwalker(int state)
{
	switch (state) {
	case 1:
		player = EV_GetPlayer(0);
		SetBankDir(92);
		EventSe_Init(2);
		EV_CameraOn();
		EV_PadOff();
		EV_CanselOn();
		EV_InitPlayer(0);
		EV_SerifPlay(816);
		EV_Wait(1);
		EV_SetPos(player, -432.95001f, -2.47f, 1261.66f);
		EV_SetAng(player, 0, 0x7E3B, 0);
		EV_Wait(1);
		EV_LookPoint(player, -438.75f, 35.0f, 1216.08f);
		EV_ClrAction(player);
		EV_SetAction(player, &action_m_m0001_miles, &MILES_TEXLIST, 1.0f, 1, 8);
		EV_CameraPos(0, 0, -432.78f, 7.8099999f, 1254.71f);
		EV_CameraAng(0, 0, 0xE369, 0x8124, 0);
		EV_CameraPos(0, 200, -433.32001f, 23.940001f, 1235.62f);
		EV_CameraAng(0, 200, 0xE369, 0x8124, 0);
		create_eggmoble(-431.51001f, 50.0f, 1163.6899f, 0, 17310, 0);
		EV_CreateObjectFunc(&CAR, SetEventObjectSSCar, -504.10001f, -7.52f, 1167.42f, 0, 15965, 0);
		EV_CreateObjectFunc(&CAR02, SetEventObjectSSCar, -384.47f, -7.52f, 1310.17f, 0, 49293, 0);
		EV_CreateObjectFunc(&CAR3, SetEventObjectSSCar, -497.72f, -7.52f, 1368.96f, 0, 48854, 0);
		EV_CreateObjectFunc(&CAR4, SetEventObjectSSCar, -499.81f, -7.52f, 1296.52f, 0, 16737, 0);
		EV_Wait(1);
		EV_SetMode(CAR, 1);
		EV_SetMode(CAR02, 1);
		EV_SetMode(CAR3, 1);
		EV_SetMode(CAR4, 1);
		EventSe_Play(0, 1336, 1800);
		EV_CreateObject(&BOY, -431.57001f, 3.0f, 1296.59f, 0, 45372, 0);
		EV_CreateObject(&OYAJI, -452.85999f, 7.0f, 1292.42f, 0, 52412, 0);
		EV_CreateObject(&FAT, -460.01999f, 5.3000002f, 1278.92f, 0, 52412, 0);
		EV_CreateObject(&LADY, -413.94f, 8.0f, 1281.87f, 0, 45374, 0);
		EV_CreateObject(&GIRL, -427.59f, 3.0f, 1286.2f, 0, 45374, 0);
		EV_CreateObject(&BOY2, -420.69f, 3.0f, 1287.15f, 0, 45374, 0);
		EV_CreateObject(&OYAJI2, -444.57999f, 7.0f, 1283.58f, 0, 52412, 0);
		EV_CreateObject(&LADY2, -450.42999f, 8.0f, 1279.9399f, 0, 52412, 0);
		EV_CreateObject(&GIRL2, -457.17999f, 3.0f, 1281.1f, 0, 52412, 0);
		EV_Wait(1);
		EV_SetMode(BOY, 0);
		EV_ClrAction(BOY);
		EV_SetMotion(BOY, MODEL_SS_PEOPLE_OBJECTS[17], MODEL_SS_PEOPLE_MOTIONS[26], ADV00_TEXLISTS[6], 0.5f, 1, 0);
		EV_SetMode(OYAJI, 0);
		EV_ClrAction(OYAJI);
		EV_SetMotion(OYAJI, *MODEL_SS_PEOPLE_OBJECTS, MODEL_SS_PEOPLE_MOTIONS[2], ADV00_TEXLISTS[6], 0.5f, 1, 0);
		EV_SetMode(FAT, 0);
		EV_ClrAction(FAT);
		EV_SetMotion(FAT, MODEL_SS_PEOPLE_OBJECTS[15], MODEL_SS_PEOPLE_MOTIONS[23], ADV00_TEXLISTS[6], 0.5f, 1, 0);
		EV_SetMode(LADY, 0);
		EV_ClrAction(LADY);
		EV_SetMotion(LADY, MODEL_SS_PEOPLE_OBJECTS[7], MODEL_SS_PEOPLE_MOTIONS[8], ADV00_TEXLISTS[6], 0.5f, 1, 0);
		EV_SetMode(GIRL, 0);
		EV_ClrAction(GIRL);
		EV_SetMotion(GIRL, MODEL_SS_PEOPLE_OBJECTS[9], MODEL_SS_PEOPLE_MOTIONS[12], ADV00_TEXLISTS[6], 0.5f, 1, 0);
		EV_SetMode(BOY2, 0);
		EV_ClrAction(BOY2);
		EV_SetMotion(BOY2,MODEL_SS_PEOPLE_OBJECTS[18], MODEL_SS_PEOPLE_MOTIONS[26],ADV00_TEXLISTS[6],0.5f,1,0);
		EV_SetMode(OYAJI2, 0);
		EV_ClrAction(OYAJI2);
		EV_SetMotion(OYAJI2, MODEL_SS_PEOPLE_OBJECTS[2], MODEL_SS_PEOPLE_MOTIONS[1], ADV00_TEXLISTS[6], 0.5f, 1, 0);
		EV_SetMode(LADY2, 0);
		EV_ClrAction(LADY2);
		EV_SetMotion(LADY2, MODEL_SS_PEOPLE_OBJECTS[7], MODEL_SS_PEOPLE_MOTIONS[8], ADV00_TEXLISTS[6], 0.5f, 1, 0);
		EV_SetMode(GIRL2, 0);
		EV_ClrAction(GIRL2);
		EV_SetMotion(GIRL2, MODEL_SS_PEOPLE_OBJECTS[10], MODEL_SS_PEOPLE_MOTIONS[12], ADV00_TEXLISTS[6], 0.5f, 1, 0);
		EV_MsgW(40, msgTbl_ev0050[TextLanguage][7]);
		EV_MsgClose();
		EV_Wait(80);
		EV_CameraPos(0, 0, -453.06f, 67.860001f, 1193.33f);
		EV_CameraAng(0, 0, 0xF269, 0xE424, 0);
		EV_SerifPlay(811);
		EV_MsgW(0, msgTbl_ev0050[TextLanguage][0]); //"\aSo you beat me to the missile,\nyou l"...
		EV_Wait(50);
		EV_CameraPos(0, 0, -458.51999f, 8.2700005f, 1296.03f);
		EV_CameraAng(0, 0, 0x2A1, 0xF101, 0);
		EV_CameraPos(0, 220, -420.26001f, 7.3099999f, 1295.88f);
		EV_CameraAng(0, 220, 0x2A1, 0xC1C, 0);
		EV_Wait(100);
		EV_MsgClose();
		EV_Wait(30);
		EV_CameraPos(0, 0, -425.09f, -1.8f, 1278.83f);
		EV_CameraAng(0, 0, 0xA17, 0x51F, 0);
		EV_Wait(10);
		EV_MsgW(0, msgTbl_ev0050[TextLanguage][1]); //"\aI will make you all pay\nfor this!"
		EV_SerifPlay(812);
		EV_Wait(30);
		EV_CameraPos(0, 30, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 30, 0x2317, 0x263, 0);
		EV_FreeObject(&BOY);
		EV_FreeObject(&LADY);
		EV_FreeObject(&GIRL);
		EV_FreeObject(&OYAJI);
		EV_FreeObject(&FAT);
		EV_FreeObject(&BOY2);
		EV_FreeObject(&LADY2);
		EV_FreeObject(&GIRL2);
		EV_FreeObject(&OYAJI2);
		eggmoble_move_normal(-431.51001f, 550.0f, 1113.6899f, 90);
		EventSe_Play(1, 1338, 1800);
		EventSe_Pitch(1, 8000, 100);
		EventSe_Volume(1, -100, 100);
		EV_Wait(100);
		EV_MsgClose();
		delete_eggmoble();
		EV_SerifPlay(818);
		EV_MsgW(40, msgTbl_ev0050[TextLanguage][8]);
		EV_MsgClose();
		EV_Wait(1);
		EV_eggmoble2(-431.51001f, 350.0f, 1163.6899f, 0, 0xFB58, 0);
		EV_Wait(3);
		ShadowEggmoble2(4.0f, 2.5f);
		EV_Wait(2);
		ChgEgg2Mod(1);
		EventSe_Pitch(1, -8000, 80);
		EventSe_Volume(1, 100, 80);
		EV_Wait(40);
		EventSe_Volume(0, 100, 1);
		EV_SerifPlay(795);
		EV_Wait(1);
		EventSe_Volume(0, -100, 100);
		EV_CameraPos(0, 10, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 10, 0xE17, 0x263, 0);
		EV_Wait(60);
		EventSe_Stop(1);
		EV_Wait(1);
		EventSe_Play(1, 1335, 1800);
		EventSe_Volume(1, 120, 1);
		EventSe_Volume(1, -100, 100);
		EV_Wait(1);
		RumbleA(0, 5);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xF17, 0x263, 0);
		EV_Wait(2);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xC17, 0x263, 0);
		EV_Wait(1);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xF17, 0x263, 0);
		EV_Wait(2);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xB17, 0x263, 0);
		EV_Wait(1);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xE17, 0x263, 0);
		EV_Wait(1);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xB17, 0x263, 0);
		EV_Wait(2);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xD17, 0x263, 0);
		EV_Wait(1);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xB17, 0x263, 0);
		EV_Wait(2);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xD17, 0x263, 0);
		EV_Wait(1);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xF17, 0x263, 0);
		EV_Wait(2);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xD17, 0x263, 0);
		EV_Wait(1);
		EV_CameraPos(0, 0, -423.34f, -0.28f, 1288.4301f);
		EV_CameraAng(0, 0, 0xE17, 0x263, 0);
		EV_Wait(40);
		EventSe_Stop(1);
		EventSe_Oneshot(740, 0, 0, 0);
		EV_CameraPos(1, 0, -443.14999f, -1.11f, 1249.12f);
		EV_CameraAng(1, 0, 0xEED, 0x1888, 0);
		EV_Wait(18);
		EventSe_Oneshot(740, 0, 0, 0);
		EV_CameraPos(1, 0, -400.64999f, 40.220001f, 1221.33f);
		EV_CameraAng(1, 0, 0x8FB, 0x13C6, 0);
		EV_Wait(12);
		EV_CameraPos(1, 0, -444.14001f, 5.04f, 1267.09f);
		EV_CameraAng(1, 0, 0xF4FB, 0xD1C6, 0);
		EV_CameraPos(1, 15, -530.15997f, 75.709999f, 1310.63f);
		EV_CameraAng(1, 15, 0xF4FB, 0xE1C6, 0);
		EV_Wait(13);
		EventSe_Oneshot(740, 0, 0, 0);
		EV_CameraPos(1, 150, -539.27002f, 79.449997f, 1320.5699f);
		EV_CameraAng(1, 150, 0xF4FB, 0xE1C6, 0);
		EV_Wait(100);
		EV_CameraPos(0, 0, -421.5f, 93.080002f, 1160.75f);
		EV_CameraAng(0, 0, 0xE2E4, 0x7760, 0);
		EV_SerifPlay(813);
		EV_MsgW(40, msgTbl_ev0050[TextLanguage][2]); //"\aYou fool!"
		EV_MsgW(0, msgTbl_ev0050[TextLanguage][3]); //"\aAway! Before I make\nmincemeat out of"...
		EV_CameraPos(1, 1000, -433.56f, 8.3999996f, 1253.92f);
		EV_CameraAng(1, 1000, 0xE4E4, 0x8057, 0);
		EV_Wait(100);
		EV_CameraPos(1, 500, -433.56f, 8.3999996f, 1253.92f);
		EV_CameraAng(1, 500, 0xE4E4, 0x8057, 0);
		EV_SerifPlay(814);
		EV_SetFace(player, "EDU");
		EV_MsgW(0, msgTbl_ev0050[TextLanguage][4]); //"\aI'm not scared... \nI'm not scared!"
		EV_Wait(100);
		EV_CameraPos(1, 100, -433.56f, 8.3999996f, 1253.92f);
		EV_CameraAng(1, 100, 0xE4E4, 0x8057, 0);
		EV_SerifPlay(815);
		EV_SetFace(player, "EAE");
		EV_MsgW(0, msgTbl_ev0050[TextLanguage][5]); //"\aI can do this!"
		EV_Wait(10);
		EV_CameraPos(1, 10, -433.56f, 8.3999996f, 1253.92f);
		EV_CameraAng(1, 10, 0xE4E4, 0x8057, 0);
		EV_Wait(20);
		EV_MsgClose();
		EV_LookFree(player);
		stopObjectAll();
		break;
	case 2:
		EventSe_Close();
		stopObjectAll();
		EV_InitPlayer(0);
		EV_deleggmoble2();
		delete_eggmoble();
		EV_FreeObject(&BOY);
		EV_FreeObject(&LADY);
		EV_FreeObject(&GIRL);
		EV_FreeObject(&OYAJI);
		EV_FreeObject(&FAT);
		EV_FreeObject(&BOY2);
		EV_FreeObject(&LADY2);
		EV_FreeObject(&GIRL2);
		EV_FreeObject(&OYAJI2);
		EV_FreeObject(&CAR);
		EV_FreeObject(&CAR02);
		EV_FreeObject(&CAR3);
		EV_FreeObject(&CAR4);
		EV_CameraOff();
		EV_PadOn();
		break;
	}
}