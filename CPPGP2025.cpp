#include <Windows.h>
#include "GameState.h"
#include "ZVector3.h"
#include "ZMatrix.h"
#include "TitleState.h"
#include "Bitmap.h"

#include "CPPGP2025.h"

#define WIN_NAME L"WinAPI State Pattern"
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

GameState* g_curState = nullptr;
HINSTANCE g_hInstance = NULL;
HWND g_hWnd = NULL;

void MatrixTest();

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:

        timeBeginPeriod(1);

        break;
    case WM_PAINT:
    {
        if (g_curState)
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            g_curState->Render(hdc);
            EndPaint(hWnd, &ps);
        }
    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        if (g_curState)
        {
            g_curState->OnKeyDown(wParam);
        }
        break;

    case WM_KEYUP:
        if (g_curState)
        {
            g_curState->OnKeyUp(wParam);
        }
        break;

    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_MBUTTONDOWN:
        if (g_curState)
        {
            g_curState->OnMouseDown(LOWORD(wParam), HIWORD(lParam), (int)wParam);
        }
        break;
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
        if (g_curState)
        {
            g_curState->OnMouseUp(LOWORD(wParam), HIWORD(lParam), (int)wParam);
        }
        break;
    case WM_MOUSEMOVE:
        if (g_curState)
        {
            g_curState->OnMouseMove(LOWORD(wParam), HIWORD(lParam));
        }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}

void SetupConsole()
{
    AllocConsole(); // 현재 프로세스에 새로운 콘솔 창을 할당
    FILE* pConsole;
    // std::out에 쓰는 모든 내용이 새로 할당된 콘솔 창에 출력되도록 세팅한다.
    freopen_s(&pConsole, "CONOUT$", "w", stdout);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLinwe, int nCmdShow)
{
    SetupConsole();
    MatrixTest();

    // 윈도우 클래스 정의
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = g_hInstance = hInstance;
    wc.lpszClassName = L"CPPGPClass";

    // 윈도우 클래스 등록
    RegisterClass(&wc);

    g_hWnd = CreateWindowEx(
        0,                      // 확장 윈도우 스타일
        L"CPPGPClass",          // 윈도우 클래스 이름
        L"CPPGP",               // 윈도우 제목 
        WS_OVERLAPPEDWINDOW,    // 윈도우 스타일

        // 크기 및 위치
        CW_USEDEFAULT, CW_USEDEFAULT, WIN_WIDTH, WIN_HEIGHT,

        NULL, // 부모 윈도우
        NULL, // 메뉴
        hInstance,
        NULL // 추가 애플리케이션 데이터
    );

    if (g_hWnd == NULL)
    {
        std::cout << "Failed to Create Window!" << std::endl;
        return 0;
    }

    // 윈도우를 화면에 표시 및 업데이트
    ShowWindow(g_hWnd, nCmdShow);
    UpdateWindow(g_hWnd);

    // 시작 상태
    ChangeState(new TitleState());

    long long preTime = timeGetTime();

    MSG msg = {};
    while (TRUE)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (WM_QUIT == msg.message)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            long long currentTime = timeGetTime();
            float elapsedTime = (currentTime - preTime) / 1000.0f;
            preTime = currentTime;

            if (g_curState)
            {
                g_curState->Update(elapsedTime);
            }

            InvalidateRect(g_hWnd, NULL, FALSE);
        }
    }

    if (g_curState)
    {
        g_curState->Exit();
        delete g_curState;
        g_curState = nullptr;
    }

    FreeConsole();

    return (int)msg.wParam;
}

void MatrixTest()
{
    ZVector3 v1(1, 2, 3);
    ZVector3 v2(4, -5, 6);

    std::cout << v2.Cross(v1) << std::endl;

    std::cout << ZVector3::Dot(v1, v2) << std::endl;
    std::cout << v1.radBetween(v1, v2) << std::endl;
    std::cout << v1.degBetween(v1, v2) << std::endl;

    ZVector3 localPoint(1.0, 1.0, 1.0);
    std::cout << "Local Space Point : " << localPoint << std::endl;

    // scale 모든 축으로 2배 확대
    ZMatrix matScale = ZMatrix::CreateScale(2.0, 2.0, 2.0);

    // Rotation : Y축 90도 회전
    const double PI = 3.1415926535897932;
    ZMatrix matRotation = ZMatrix::CreateRotationY(PI / 2.0);

    // Translation : 월드 공간의 (5, 6, 7) 위치로 이동
    ZMatrix matTranslation = ZMatrix::CreateTranslation(5, 6, 7);

    // 변환을 순차적으로 적용
    ZVector3 pointAfterScale = localPoint.Transform(matScale);
    std::cout << pointAfterScale << std::endl;

    ZVector3 pointAfterRotation = pointAfterScale.Transform(matRotation);
    std::cout << pointAfterRotation << std::endl;

    ZVector3 finalWorldPoint = pointAfterRotation.Transform(matTranslation);
    std::cout << finalWorldPoint << std::endl;

    // 한번에 계산
    ZMatrix worldMat = matScale * matRotation * matTranslation;
    ZVector3 finalWorldPointByMatrix = localPoint.Transform(worldMat);
    std::cout << finalWorldPointByMatrix << std::endl;
}

void ChangeState(GameState* newState)
{
    if (g_curState)
    {
        g_curState->Exit();
        delete g_curState;
    }

    g_curState = newState;
    g_curState->Enter(g_hWnd);
}
