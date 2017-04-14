/**
 *	 Program With Persist Data Year 1, Semester II, Program Course DT228 BSc In Computer Science
 *
 *   In this assignment we had to create a utility program called readMP3.c
 *   This utility file get some metadata information from the mp3 file by
 *   reading the MP3 audio and then display some information on the screen.
 *
 *	 Program created by Iosif Dobos, Nial Kelly @copyright all rights are reserved
 *	 Date: 15/03/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declare symbolic name
#define SIZE 31

//declare the structure tag
struct mp3
{
    char check_tag[4];
    char title[SIZE];
    char artist[SIZE];
    char album [SIZE];
    int year[SIZE];
    char genre[SIZE];

};

//declare function prototype

//declare my global genre array of pointers and asign the names
char *my_genre_array[80] = {
        "Blues", "Alternative", "AlternRock", "Top 40",
        "Classic Rock", "Ska", "Bass", "Christian Rap",
        "Country", "Death Metal", "Soul", "Pop/Funk",
        "Dance", "Pranks", "Punk", "Jungle",
        "Disco", "Soundtrack", "Space", "Native American",
        "Funk", "Euro-Techno", "Mediative", "Cabaret",
        "Grunge", "Ambient", "Instrumental Pop", "New Wave",
        "Hip-Hop", "Trip-Hop", "Instrumental Rock", "Psychadelic",
        "Jazz", "Vocal", "Ethnic", "Rave",
        "Metal", "Jazz+Funk", "Gothic", "Showtunes",
        "New Age", "Fusion", "Darkwave", "Trailer",
        "Oldies", "Trance", "Techno-Industrial", "Lo-FI",
        "Other", "Classical", "Electronic", "Tribal",
        "Pop", "Instrumental", "Pop-Folk", "Acid Punk",
        "R&B", "Acid", "Eurodance", "Acid Jazz",
        "Rap", "House", "Dream", "Polka",
        "Reggae", "Game", "Southern Rock", "Retro",
        "Rock", "Sound Clip", "Comedy", "Musical",
        "Techno", "Gospel", "Cult", "Rock & Roll",
        "Industrial", "Noise", "Gangsta", "Hard Rock"
    };

//main function
int main(int argc, char *argv[])
{
    //declare my file pointer
    FILE *fp;

    //declare my structure variable
    struct mp3 track;

    if ( argc != 2 )
    {
        printf("\nPlease enter only one file name at a time");
        exit(1);
    }
    if ( (fp = fopen(argv[1], "rb")) == NULL)
    {
        printf("\nSorry cannot open the mp3 file");
        exit(1);
    }
    else
    {
        printf("\nMp3 file opened successfully!!! ");
    }


    fseek( fp, -128 * sizeof(char), SEEK_END);
    fread( &track.check_tag, 3 * sizeof( char ), 1, fp);
    track.check_tag[3] = '\0';

    //check if valid audio tah is present
    if ( strcmp(track.check_tag, "TAG") != 0 )
    {
        printf("\nThe file does not have a valid audio tag.");
        exit(1);
    }
    else
    {
        printf("\nFile has a valid tag");
    }

    track.title[0] = '\0';
    fread(&track.title, 30 * sizeof(char), 1, fp);
    if (track.title[0] == '\0')
    {
        strcpy(track.title, "Unknown");
    }
    track.title[30] = '\0';

    track.artist[0] = '\0';
    fread(&track.artist, 30 * sizeof(char),1,fp);
    if( track.artist[0] == '\0')
    {
        strcpy(track.artist, "Unknown");
    }
    track.artist[30] = '\0';


    track.album[0] = '\0';
    fread(&track.album, 30*sizeof(char), 1, fp);
    if (track.album[0] == '\0')
    {
        strcpy(track.album, "Unknown");
    }
    track.album[30] = '\0';


    track.year[0] = '\0';
    fread(&track.year, 4*sizeof(char), 1, fp);
    if (track.year[0] == '\0')
    {
        strcpy(track.year, "Unknown");//Display 0000 as message if no year found
    }
    track.year[4] = '\0';


    //Skip the 30 bits allocated for comments and read the genre field
    fseek(fp, 30, SEEK_CUR);

    track.genre[0] = '\0';
    fread(&track.genre,3*sizeof(char), 1, fp);

    if (track.genre[0] == '\0' || ((*track.genre) > 125) || ((*track.genre) < 0) )
    {
        strcpy(track.genre, "Unknown");
    }
    else {
        strcpy(track.genre, my_genre_array[*track.genre]);//Copy from genres array the element coresponding to number read from file
    }
    track.genre[20] = '\0';




    //Display the information required
    printf("\n\n Title  : %s \n\n Artist : %s \n\n Album  : %s \n\n Year   : %s \n\n Genre  : %s\n\n", track.title,  track.artist,  track.album, track.year, track.genre);


    //Close the file
    fclose(fp);


    return 0;
}
