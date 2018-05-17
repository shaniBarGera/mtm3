#include <stdlib.h>
#include <string.h>
#include "series.h"

struct series {
    char* name;
    int episodesNum;
    char* genre;
    int ages[2];
    double episodeDuration;
};

MapDataElement copySeries(MapDataElement src) {
    if (!src) {
        return NULL;
    }
    Series dst = malloc(sizeof(*dst));
    if (!dst) {
        return NULL;
    }
    Series res = (Series)src; //doing this right?
    strcpy(dst->name, res->name);//dunno if need another malloc for this
    dst->episodesNum = res->episodesNum;
    strcpy(dst->genre, res->genre);
    dst->ages[0] = res->ages[0];
    dst->ages[1] = res->ages[1];
    dst->episodeDuration = res->episodeDuration;
    return dst;
}
MapKeyElement seriesCopyName(MapKeyElement src) {
    char* dst = malloc(strlen(src)+1);
    strcpy(dst, src);
    return dst;
}
void deleteSeries(MapDataElement series) { //Do it better
    free(series);
}
void seriesDeleteName(MapKeyElement name) {
    free(name);
}
int seriesCompareNames(MapKeyElement name1, MapKeyElement name2) {
    return strcmp((char*)name1, (char*)name2);
}
Series createSeries(const char* name, int episodesNum,
                               Genre genre, int* ages, int episodesDuration) {
    Series series = malloc(sizeof(series));
    strcpy(series->name, name);
    series->episodesNum = episodesNum;
    series->genre = genre;
    series->ages[0] = ages[0];
    series->ages[1] = ages[1];
    series->episodeDuration = episodesDuration;
    return series;
}
