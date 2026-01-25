#include <stdio.h>
#include <time.h>   //Biblioteket henter og viser den aktulle tid
#include <unistd.h> //Vi vil jo gerne have der går et sekundt fra updateringerne i lykken, derfor bruges denne bibliotek tik at bruge sleep()

//programmets startpunkt som retunere en integer
/*
int main(){


    time_t now;     //variablen now gemmer det aktuelle tidspunkt i sekunder
    time(&now);     //funktionen time gemmer det aktulle tidspunkt i variablen now


    printf("Digital ur: %s", ctime (&now));     //ctime konvetere tiden gemt i now til meneskelig læsbar

    sleep(1);

    return 0;
}

*/











// Sejere ur:


































#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    // Initialiser SDL og SDL_ttf
    if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0) {
        printf("Kunne ikke initialisere SDL eller TTF: %s\n", SDL_GetError());
        return 1;
    }

    // Opret vindue
    SDL_Window *window = SDL_CreateWindow("Digitalt Ur", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Indlæs skrifttype
    TTF_Font *font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 72);
    if (!font) {
        printf("Kunne ikke indlæse skrifttype: %s\n", TTF_GetError());
        return 1;
    }

    // Hovedløkke
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Hent tid
        time_t now = time(NULL);
        struct tm *local = localtime(&now);

        // Formatér tid
        char timeText[9];
        snprintf(timeText, sizeof(timeText), "%02d:%02d:%02d", local->tm_hour, local->tm_min, local->tm_sec);

        // Ryd skærmen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render tekst
        SDL_Color white = {255, 255, 255};
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, timeText, white);
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        // Vis tekst i midten af vinduet
        int textWidth = textSurface->w;
        int textHeight = textSurface->h;
        SDL_Rect destRect = {400 - textWidth / 2, 300 - textHeight / 2, textWidth, textHeight};
        SDL_FreeSurface(textSurface);

        SDL_RenderCopy(renderer, textTexture, NULL, &destRect);
        SDL_DestroyTexture(textTexture);

        SDL_RenderPresent(renderer);

        SDL_Delay(1000); // Vent 1 sekund
    }

    // Ryd op
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
