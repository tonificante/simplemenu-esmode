#ifndef GLOBALS_DEFINED
#define GLOBALS_DEFINED

#define BROWSING_GAME_LIST 0
#define SELECTING_EMULATOR 1
#define CHOOSING_GROUP 2
#define SETTINGS_SCREEN 3
#define SELECTING_SECTION 4
#define SHUTTING_DOWN 5
#define BROWSING_GAME_LIST_AFTER_TIMER 6
#define AFTER_RUNNING_LAUNCH_AT_BOOT 7
#define HELP_SCREEN_1 8
#define HELP_SCREEN_2 9

#include <pthread.h>
#include <SDL/SDL_timer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "../headers/hashtable.h"
#include "../headers/constants.h"

#if defined TARGET_OD_BETA
#include <shake.h>
#endif

extern int updateScreenFlag;
extern int launchAtBoot;

extern SDL_Surface *screen;
extern int displayLogo;
/* STATUS */
extern int nullUpdate;
extern char *errorMessage;
extern int running;
extern int itsStoppedBecauseOfAnError;
extern int thereIsACriticalError;
extern int favoritesChanged;
extern int favoritesSectionSelected;
extern int returnTo;
extern int currentSectionNumber;
extern int currentCPU;
extern int fullscreenMode;
extern int hotKeyPressed;
extern int aKeyComboWasPressed;
extern int currentlySectionSwitching;
extern int currentState;
extern int previousState;
extern int loading;
extern int isPicModeMenuHidden;
extern int isSuspended;
extern int activeGroup;
extern int beforeTryingToSwitchGroup;
extern int chosenSetting;
extern int chosenChoosingOption;
extern char currentGameNameBeingDisplayed [3000];
extern SDL_TimerID timeoutTimer;
extern SDL_TimerID shutdownTimer;
extern SDL_TimerID picModeHideMenuTimer;
extern SDL_TimerID picModeHideLogoTimer;
extern SDL_TimerID hideHeartTimer;
extern SDL_TimerID batteryTimer;
extern Mix_Music *bgmusic;
extern struct dirent **playlist;
extern int playlistLength;
extern int *playlistIndexArr;
extern char *currentSongPath;
extern int playlistCurrentIndex;

typedef struct thread_picture {
	  SDL_Surface* display;
	  SDL_Surface *image;
	  int x;
	  int y;
	  int xx;
	  int yy;
	  double newwidth;
	  double newheight;
	  int transparent;
	  int smoothing;
} threadPicture;

/* QUANTITIES */
extern int MAX_GAMES_IN_SECTION;
extern int ITEMS_PER_PAGE;
extern int FULLSCREEN_ITEMS_PER_PAGE;
extern int MENU_ITEMS_PER_PAGE;
extern int favoritesSectionNumber;
extern int favoritesSize;
extern int menuSectionCounter;
extern int sectionGroupCounter;
extern int gamesInPage;

/* SETTINGS */
extern int TIDY_ROMS_OPTION;
extern int FULL_SCREEN_FOOTER_OPTION;
extern int FULL_SCREEN_MENU_OPTION;
extern int THEME_OPTION;
extern int SCREEN_TIMEOUT_OPTION;
extern int DEFAULT_OPTION;
extern int USB_OPTION;
extern int SHUTDOWN_OPTION;
extern int HELP_OPTION;
extern int ITEMS_PER_PAGE_OPTION;
extern char mediaFolder[1000];
extern char musicPath[1000];
extern int stripGames;
extern int useCache;
extern int shutDownEnabled;
extern int selectedShutDownOption;
extern int footerVisibleInFullscreenMode;
extern int menuVisibleInFullscreenMode;
extern int timeoutValue;
extern int OC_UC;
extern int OC_NO;
extern int OC_OC;
extern int OC_SLEEP;
extern int backlightValue;
extern int hdmiChanged;
extern pthread_t myThread;

/* THEME */
extern char *themes[100];
extern int themeChanged;
extern int activeTheme;
extern int themeCounter;
extern int currentMode;
extern char menuFont[1000];
extern int baseFont;
extern int fontSize;
extern int transparentShading;
extern int footerOnTop;
extern char simpleBackground[1000];
extern char fullscreenBackground[1000];
extern char favoriteIndicator[1000];
extern char sectionGroupsFolder[1000];
extern int itemsPerPage;
extern int itemsPerPageFullscreen;
extern int itemsSeparation;
extern char textXFont[1000];
extern char batt1[1000];
extern char batt2[1000];
extern char batt3[1000];
extern char batt4[1000];
extern char batt5[1000];
extern char battCharging[1000];
extern int battX;
extern int battY;
extern int text1FontSize;
extern int text1X;
extern int text1Y;
extern int text1Alignment;
extern int text2FontSize;
extern int text2X;
extern int text2Y;
extern int text2Alignment;
extern int text3FontSize;
extern int text3X;
extern int text3Y;
extern int text3Alignment;
extern int gameListAlignment;
extern int gameListX;
extern int gameListY;
extern int gameListWidth;
extern int gameListPositionFullScreen;
extern int artWidth;
extern int artHeight;
extern int artX;
extern int artY;
extern int artTextDistanceFromPicture;
extern int artTextLineSeparation;
extern int artTextFontSize;
extern int systemWidth;
extern int systemHeight;
extern int systemX;
extern int systemY;
extern int fontSize;
extern int colorfulFullscreenMenu;
extern int fontOutline;
extern int displaySectionGroupName;
extern int showArt;
extern int refreshRequest;

extern int displayGameCount;
extern char gameCountFont[1000];
extern int gameCountFontSize;
extern int gameCountX;
extern int gameCountY;
extern int gameCountAlignment;
extern int gameCountFontColor[3];
extern char gameCountText[100];

/* STRUCTS */
struct OPKDesktopFile {
	char parentOPK[200];
	char name[200];
	char displayName[200];
	char category[200];
	int isConsoleApp;
};

struct StolenGMenuFile {
	char title[200];
	char exec[200];
	char params[600];
	int isConsoleApp;
};

struct Favorite {
	char section[300];
	char name[300];
	char alias[300];
	char emulatorFolder[200];
	char executable[200];
	char filesDirectory[400];
	int isConsoleApp;
	int frequency;
};

struct RomPreferences {
	int emulator;
	int emulatorDir;
	int frequency;
};

struct Rom {
	char *name;
	char *alias;
	char *directory;
	struct RomPreferences preferences;
	int isConsoleApp;
};

struct AutostartRom {
	struct Rom *rom;
	char *emulator;
	char *emulatorDir;
};

struct Node  {
	struct Rom  *data;
	struct Node *next;
	struct Node *prev;
};

struct SectionGroup {
	char groupPath[1000];
	char groupName[25];
	char groupBackground[1000];
	SDL_Surface *groupBackgroundSurface;
};

struct MenuSection {
	int counted;
	char sectionName[250];
	char fantasyName[250];
	char *emulatorDirectories[10];
	char *executables[10];
	char filesDirectories[400];
	char fileExtensions[150];
	char systemLogo[300];
	SDL_Surface *systemLogoSurface;
	char systemPicture[300];
	SDL_Surface *systemPictureSurface;
	char aliasFileName[300];
	int hidden;
	int currentPage;
	int currentGameInPage;
	int realCurrentGameNumber;
	int alphabeticalPaging;
	int totalPages;
	int gameCount;
	int initialized;
	int onlyFileNamesNoExtension;
	int fullScreenMenuBackgroundColor[3];
	int fullscreenMenuItemsColor[3];
	int bodyBackgroundColor[3];
	int menuItemsFontColor[3];
	int bodySelectedTextBackgroundColor[3];
	int bodySelectedTextTextColor[3];
	int pictureTextColor[3];
	struct Node* currentGameNode;
	struct Node *head;
	struct Node *tail;
	hashtable_t *aliasHashTable;
	int activeExecutable;
	int activeEmulatorDirectory;
	char category[100];
	char scaling[2];
	char background[1000];
	SDL_Surface *backgroundSurface;
	int hasDirs;
//	char *fileList[50000];
};

extern struct SectionGroup sectionGroups[100];
extern int sectionGroupStates[100][100][5];
extern struct MenuSection menuSections[100];
extern struct Favorite favorites[2000];

/* CONTROL */
extern uint8_t *keys;
extern SDL_Joystick *joystick;
extern int BTN_Y;
extern int BTN_B;
extern int BTN_A;
extern int BTN_X;
extern int BTN_START;
extern int BTN_SELECT;
extern int BTN_R;
extern int BTN_UP;
extern int BTN_DOWN;
extern int BTN_LEFT;
extern int BTN_RIGHT;
extern int BTN_L1;
extern int BTN_R1;
extern int BTN_L2;
extern int BTN_R2;

#if defined TARGET_OD_BETA
extern Shake_Device *device;
extern Shake_Effect effect;
extern int effect_id;
extern Shake_Effect effect1;
extern int effect_id1;
#endif

/* SCREEN */
extern int MAGIC_NUMBER;
extern int SCREEN_HEIGHT;
extern int SCREEN_WIDTH;
extern int HDMI_WIDTH;
extern int HDMI_HEIGHT;
extern double SCREEN_RATIO;
extern int hdmiEnabled;

/* MISC */
extern time_t currRawtime;
extern struct tm * currTime;
extern int lastSec;
extern int lastMin;
extern int lastChargeLevel;
extern pthread_t clockThread;
extern pthread_mutex_t lock;

#endif
