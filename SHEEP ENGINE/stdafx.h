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

// 싱글톤
#include "SINGLETON.h"
// 컬러 define
#include "COLOR.h"
// safe_release
#include "SAFE_RELEASE.h"

using namespace std;


//-------------------------------------//


// 윈도우 창화면 = true, 전체화면 = false
#define WinScreen true
// 초기화 컬러
#define SCENE_COLOR WHITE

// 제목
#define NAME "Sheep Engine"
// 가로
#define _Width  800
// 세로
#define _Height 500	