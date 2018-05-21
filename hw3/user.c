#include "user.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "map.h"
#include "set.h"
#include "series.h"
#include "mtm_ex3.h"


struct user {
    char* username;
    int age;
    Set favorites;
    Set friends;
};

MapDataElement copyUser(MapDataElement src) {
    if (!src) {
        return NULL;
    }
    User dst = malloc(sizeof(*dst));
    if (!dst) {
        return NULL;
    }
    User res = (User)src; //doing this right?
    dst->username = malloc(strlen(res->username)+1);
    strcpy(dst->username, res->username);
    dst->age = res->age;
    dst->favorites = setCopy(res->favorites);
    dst->friends = setCopy(res->friends);
    return dst;
}
MapKeyElement userCopyName(MapKeyElement src) {
    char* dst = malloc(strlen(src)+1);
    strcpy(dst, src);
    return dst;
}
void deleteUser(MapDataElement user) { //Do it better
    if (!user)
        return;
    free(user);
}
void userDeleteName(MapKeyElement name) {
    free(name);
}
int userCompareNames(MapKeyElement name1, MapKeyElement name2) {
    return strcmp((char*)name1, (char*)name2);
}
int userCompareNamesForSet(MapKeyElement user1, MapKeyElement user2) {
    return strcmp(((User)user1)->username, ((User)user2)->username);
}
User createUser(const char* newUsername, int newAge) {
<<<<<<< HEAD
    User user = malloc(sizeof(*user));
    if(!user) return NULL;
    user->username = malloc(sizeof(char)*(strlen(newUsername)+1));
    if(!user->username) return NULL;
=======
    User user = malloc(sizeof(user));
    user->username = malloc(strlen(newUsername)+1);
>>>>>>> 606ac3901869c2be0c2b542760f17a6cf4d51854
    strcpy(user->username, newUsername);
    user->age = newAge;
    user->favorites = setCreate(copySeries, deleteSeries, seriesCompareNames);
    user->friends = setCreate(copyUser, deleteUser, userCompareNames);
    return user;
}
//I guess the next function should be USER_STATUS (which we should implement), maybe later
MtmFlixResult userAddFavorite(User user, Series series) {
    if (!user || !series)
        return MTMFLIX_NULL_ARGUMENT;
    //checking if user age is in series age range
    //(should be defined separately in a static function)
    //(should probably make this check in mtmflix.c and not here):
    int* seriesAges = seriesGetAges(series);
<<<<<<< HEAD
    if (seriesAges && (user->age < seriesAges[0] || user->age > seriesAges[1]))
        return MTMFLIX_USER_NOT_IN_THE_RIGHT_AGE;
=======
    if (seriesAges)
        if (user->age < *seriesAges || user->age > *(seriesAges + 1))
            return MTMFLIX_USER_NOT_IN_THE_RIGHT_AGE;
>>>>>>> 606ac3901869c2be0c2b542760f17a6cf4d51854
    if (setAdd(user->favorites, series) == SET_OUT_OF_MEMORY)
        return MTMFLIX_OUT_OF_MEMORY;
    return MTMFLIX_SUCCESS;
}
MtmFlixResult userRemoveFavorite(User user, Series series) {
    if (!user || !series)
        return MTMFLIX_NULL_ARGUMENT;
    setRemove(user->favorites, series);
    return MTMFLIX_SUCCESS;
}
MtmFlixResult userAddFriend(User user, User friend) {
    if (!user || !friend)
        return MTMFLIX_NULL_ARGUMENT;
    setAdd(user->friends, friend);
    return MTMFLIX_SUCCESS;
}
MtmFlixResult userRemoveFriend(User user, User friend) {
    if (!user || !friend)
        return MTMFLIX_NULL_ARGUMENT;
    setRemove(user->friends, friend);
    return MTMFLIX_SUCCESS;
}
<<<<<<< HEAD
const char* printUser(User user) {
    return mtmPrintUser(user->username, user->age, setGetFirst(user->friends),
                        setGetFirst(user->favorites));
=======
const char* printUser(char* user_name, User user) {
    if(!user) return user_name;
    return mtmPrintUser(user->username, user->age, setGetFirst(user->friends),
                 setGetFirst(user->favorites));
    
void printUser(User user) { //remove this function
    printf("%s\n%d", user->username, user->age);
>>>>>>> 606ac3901869c2be0c2b542760f17a6cf4d51854
}
