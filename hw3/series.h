#ifndef HW3_SERIES_H
#define HW3_SERIES_H
#include "map.h"
#include "mtm_ex3.h"

typedef struct series* Series;

MapDataElement copySeries(MapDataElement src);
MapKeyElement seriesCopyName(MapKeyElement src);
void deleteSeries(MapDataElement user);
void seriesDeleteName(MapKeyElement name);
int seriesCompareNames(MapKeyElement name1, MapKeyElement name2);
int seriesCompareNamesForSet(MapKeyElement series1, MapKeyElement series2);
int seriesCompareGenres(Genre genre1, Genre genre2);
Series createSeries(const char* name, int episodesNum,
                    Genre genre, int* ages, int episodesDuration);
int* seriesGetAges(Series series);
const char* seriesGetGenre(Series series);
Series createSeries(const char* name, int episodesNum,
                    Genre genre, int* ages, int episodesDuration);
int* seriesGetAges(Series series);
<<<<<<< HEAD
const char* printSeries(Series series);


=======
/*const char* genres[] = { "SCIENCE_FICTION", "DRAMA", "COMEDY", "CRIME",
                           "MYSTERY", "DOCUMENTARY", "ROMANCE", "HORROR"};
 */
>>>>>>> 606ac3901869c2be0c2b542760f17a6cf4d51854
#endif //HW3_SERIES_H
