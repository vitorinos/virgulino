#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define SW_NAME                         "virgulino"

#define HOME_ENV                        "HOME"
#define VIRGULINO_DIR                   "/.virgulino/"
#define KEY_FILE                        "key.vig"
#define DIR_LEN                         256

#define HIGHER_CHAR                     126
#define LOWER_CHAR                      32

// MACROS ::
#define NEW(type)                       ((type *) calloc (1, sizeof((type))))
#define _NEW(type, size)                ((type *) calloc (size, sizeof (type)))

typedef struct _enc_t EncodeType;
struct _enc_t {
    bool vigenere;
    bool ceasar;
    bool rand_numbs;
};

typedef enum _hide_t HideType;
enum _hide_t {
    ASCII,
    PNG,
    NONE,
};

typedef struct _msg_t MessagePack;
struct _msg_t {
    char * message;       
    char * filepath;
    char * key;

    size_t message_len;
    
    bool encode;
    EncodeType encode_type;
    short int salt;         // ceasar case ::

    HideType hide_type;
};

//prototypes ::
void init_message_pack (MessagePack * pack);
void destroy_message_pack (MessagePack * pack);

//functions ::
void
init_message_pack (MessagePack * pack) {
    pack->message = NULL;
    pack->filepath = NULL;
    pack->key = NULL;

    pack->message_len = 0;
    
    pack->encode = false;
    pack->encode_type.vigenere = false;
    pack->encode_type.ceasar = false;
    pack->encode_type.rand_numbs = false;

}

void
destroy_message_pack (MessagePack * pack) {
    assert (pack);
    assert (pack->message);

    free (pack->message);

   /* if (pack->key)
        free (pack->key);
   */
   /* if (pack->filepath)
        free (pack->filepath);*/
}
#endif /* _DEFINITIONS_H_ */
