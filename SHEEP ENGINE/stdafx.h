#pragma once

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")

#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <array>
#include <string>

// �̱���
#include "SINGLETON.h"
// �÷� define
#include "COLOR.h"
// safe_release
#include "SAFE_RELEASE.h"

using namespace std;


//-------------------------------------//


// ������ âȭ�� = true, ��üȭ�� = false
#define WinScreen true
// �ʱ�ȭ �÷�
#define SCENE_COLOR WHITE

// ����
#define NAME "Sheep Engine"
// ����
#define _Width  800
// ����
#define _Height 500	