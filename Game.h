#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Snake - Angel - 12GD" };

// Change the window dimensions here
float g_WindowWidth{ 700 };
float g_WindowHeight{ 700 };
#pragma endregion gameInformation



#pragma region ownDeclarations
//colors
const Color4f g_White{ 1, 1, 1, 1 }, g_Black{ 0, 0, 0, 1 }, g_Red{ 1,0,0,1 }, g_Green{ 0,1,0,1 };

//grid
const float g_CellSize{ 25 };
const int g_NrCols{ int(g_WindowWidth / g_CellSize) }, g_NrRows{ int(g_WindowHeight / g_CellSize) };
const int g_GridSize{ g_NrCols * g_NrRows };

/* Functional elements of the snake */
Rectf* pCells{ new Rectf[g_GridSize] {} };
int g_FruitIdx{}, g_NrFrames{}, g_Score{}, g_SnakeLength{};
float g_AccumulatedTime{}, g_SpeedFactor{};
int* g_Snake{};

bool g_UpdateFruit{}, g_ShowInfo{}, g_SnakeMoving{}, g_GameOver{}, g_ShowDifficulty{}, g_StartScreen{};

//direction
enum class Direction { left, right, up, down, none };
Direction g_Dir{};

/* Graphics of the snake */
const Point2f g_InfoPos{ g_WindowWidth / 2 - 40,g_WindowHeight - 4 * g_CellSize };
Texture g_SnakeGraphics{}, g_InfoTexture{}, g_Info2Texture{}, g_InfoBoxTexture{}, g_ScoreTexture{}, g_ScoreNrTexture{},
g_DifficultyTexture{}, g_GameOverTexture{}, g_GameOver2Texture{}, g_EndScoreTexture{}, g_EndScoreNrTexture{}, g_TitleTexture{},
g_Title2Texture{}, g_StartTexture{}, g_StartCreditsTexture{}, g_CreditNamesTexture{};
enum class SnakePart{ head, tail, body, corner};

// Declare your own functions here
/* initializing resources */
void InitTextures();
void InitGrid();
void InitSnake();
void InitFruit();

//draw functions
void DrawGrid();
void DrawSnake();
void DrawSnakeHead();
void DrawSnakeBody();
void DrawSnakeTail();
void DrawFruit();
void DrawDifficulty();
void DrawGameOver();
void DrawStartScreen();

void MoveSnake(float elapsedSec);

bool DidSnakeGetFruit();
bool SelfCollision();
int GetCellIdx(const Point2f& point);
Rectf GetSrcRect(const SnakePart& snk, const Direction& dir1, Direction dir2 = Direction::none);

//menu
void ShowInfo();
void PrintInfo();
void DrawInfo();
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
