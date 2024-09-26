#include <windows.h>
#include <stdio.h>

#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 100
#define GRID_SIZE 3

// Global variables
HWND hwndButtons[GRID_SIZE][GRID_SIZE];  // Button handles for the grid
char board[GRID_SIZE][GRID_SIZE];        // To keep track of 'X' and 'O'
char currentPlayer = 'X';                // Start with player 'X'

// Function prototypes
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void CheckWinner(HWND hwnd);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "TicTacToeWindowClass";
    WNDCLASS wc = {0};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Tic-Tac-Toe",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 
        GRID_SIZE * BUTTON_WIDTH + 20, GRID_SIZE * BUTTON_HEIGHT + 40, 
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            // Initialize the grid buttons and the board
            for (int row = 0; row < GRID_SIZE; row++) {
                for (int col = 0; col < GRID_SIZE; col++) {
                    hwndButtons[row][col] = CreateWindow(
                        "BUTTON", 
                        "", 
                        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                        10 + col * BUTTON_WIDTH, 10 + row * BUTTON_HEIGHT, 
                        BUTTON_WIDTH, BUTTON_HEIGHT,
                        hwnd, 
                        (HMENU)(row * GRID_SIZE + col), 
                        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
                        NULL
                    );
                    board[row][col] = ' ';
                }
            }
            break;

        case WM_COMMAND: {
            int id = LOWORD(wParam);
            int row = id / GRID_SIZE;
            int col = id % GRID_SIZE;

            if (board[row][col] == ' ') {
                // Set the text on the button and update the board
                char buffer[2] = {currentPlayer, '\0'};
                SetWindowText(hwndButtons[row][col], buffer);
                board[row][col] = currentPlayer;

                // Check for a winner
                CheckWinner(hwnd);

                // Switch player
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

// Function to check if there's a winner or a tie
void CheckWinner(HWND hwnd) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < GRID_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            MessageBox(hwnd, (board[i][0] == 'X') ? "Player X wins!" : "Player O wins!", "Game Over", MB_OK);
            PostQuitMessage(0);
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            MessageBox(hwnd, (board[0][i] == 'X') ? "Player X wins!" : "Player O wins!", "Game Over", MB_OK);
            PostQuitMessage(0);
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        MessageBox(hwnd, (board[0][0] == 'X') ? "Player X wins!" : "Player O wins!", "Game Over", MB_OK);
        PostQuitMessage(0);
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        MessageBox(hwnd, (board[0][2] == 'X') ? "Player X wins!" : "Player O wins!", "Game Over", MB_OK);
        PostQuitMessage(0);
    }

    // Check for a tie
    int emptyCells = 0;
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (board[row][col] == ' ') {
                emptyCells++;
            }
        }
    }

    if (emptyCells == 0) {
        MessageBox(hwnd, "It's a tie!", "Game Over", MB_OK);
        PostQuitMessage(0);
    }
}
