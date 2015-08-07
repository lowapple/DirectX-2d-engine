#pragma once
//Safe_Release
#define SAFE_RELEASE(x) if(x) { x->Release(); x = NULL; } 