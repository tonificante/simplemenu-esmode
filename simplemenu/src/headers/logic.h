#include "../headers/globals.h"
#ifndef LOGIC
#define LOGIC
void generateError(char *pErrorMessage, int pThereIsACriticalError);
void quit();
#ifndef TARGET_PC
void executeCommand (char *emulatorFolder, char *executable, char *fileToBeExecutedWithFullPath, int isConsoleApp);
#else
void executeCommandPC (char *executable, char *fileToBeExecutedWithFullPath);
#endif
void loadGameList(int refresh);
void loadFavoritesSectionGameList();
int countFiles (char* directoryName, char *fileExtensions);
int countGamesInPage();
int countGamesInSection();
int doesFavoriteExist(char *name);
void setSectionsState(char *states);
void determineStartingScreen(int sectionCount);
int getFirstNonHiddenSection(int sectionCount);
struct Favorite findFavorite(char *name);
void selectRandomGame();
int compareFavorites(const void *s1, const void *s2);
FILE *getCurrentSectionAliasFile();
char *getRomRealName(char *nameWithoutExtension);
char *getAlias(char *romName);
char *getFileNameOrAlias(struct Rom *rom);
int theSectionHasGames(struct MenuSection *section);
int recursivelyScanDirectory (char *directory, char* files[], int i);
int scanDirectory(char *directory, char* files[], int i);
int findDirectoriesInDirectory (char *directory, char* files[], int i);
int is43();
#endif
