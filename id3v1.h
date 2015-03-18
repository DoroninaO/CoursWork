

#ifndef NUL
#define NUL '\0'
#endif

#define TAG_SIZE 128
#define TRACK_SIZE 30
#define ARTIST_SIZE 30
#define ALBUM_SIZE 30
#define YEAR_SIZE 4
#define COMMENT_SIZE 28

#define TRUE 1
#define FALSE 0

/**
 * ID3v1.1 structure:
 * Byte  0  -   2 ( 3 bytes) : "TAG"
 * Byte  3  -  32 (30 bytes) : Track Name
 * Byte 33  -  62 (30 bytes) : Artist Name
 * Byte 63  -  92 (30 bytes) : Album Name
 * Byte 93  -  96 ( 4 bytes) : Year
 * Byte 97  - 124 (28 bytes) : Comment
 * Byte 125       ( 1 byte ) : Always set to 0
 * Byte 126       ( 1 byte ) : Track Number
 * Byte 127       ( 1 byte ) : Genre Number
 
 **/
typedef struct _id3v1_tag
{
  char track_name[TRACK_SIZE];
  char artist[ARTIST_SIZE];
  char album[ALBUM_SIZE];
  char year[YEAR_SIZE];
  char comment[COMMENT_SIZE];
  unsigned char zero;
  unsigned char trackno;
  unsigned char genre;
} __attribute__ ((packed)) id3v1_tag;

id3v1_tag *id3v1_tag_allocate (void);
void id3v1_tag_free (id3v1_tag * tag);
id3v1_tag *id3v1_tag_read (char *file_name);
int id3v1_tag_write (char *file_name, id3v1_tag * tag);
int id3v1_tag_rip (char *file_name);
int id3v1_tag_set_track (char *track_name, id3v1_tag * tag);
int id3v1_tag_set_artist (char *artist, id3v1_tag * tag);
int id3v1_tag_set_album (char *album, id3v1_tag * tag);
int id3v1_tag_set_year (char *year, id3v1_tag * tag);
int id3v1_tag_set_trackno (unsigned char track_no, id3v1_tag * tag);
int id3v1_tag_set_comment (char *comment, id3v1_tag * tag);
int id3v1_tag_set_genre (char genre, id3v1_tag * tag);
char *id3v1_tag_get_track (id3v1_tag * tag);
char *id3v1_tag_get_artist (id3v1_tag * tag);
char *id3v1_tag_get_album (id3v1_tag * tag);
char *id3v1_tag_get_year (id3v1_tag * tag);
char id3v1_tag_get_trackno (id3v1_tag * tag);
char *id3v1_tag_get_comment (id3v1_tag * tag);
unsigned char id3v1_tag_get_genre (id3v1_tag * tag);
char *get_genre_string (unsigned char genre_no);
unsigned char get_genre_number (char *genre_string);
char *alloc_str (int size);
 
