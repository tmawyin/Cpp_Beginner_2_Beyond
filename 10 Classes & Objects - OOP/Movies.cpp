/******************************************************************
 * Section 13 Challenge
 * Movies.h
 *
 * Models a collection of Movies as a std::vector
 *
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

/*************************************************************************
  add_movie expects the name of the move, rating and watched count

  It will search the movies vector to see if a movie object already exists
  with the same name.

  If it does then return false since the movie already exists
  Otherwise, create a movie object from the provided information
  and add that movie object to the movies vector and return true
  *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    // Let's find if the movie exist in the vector
    for (const auto& m : movies) {
        if (m.get_name() == name) { return false; }
    }
    // Couldn't find movie, let's add it
    movies.push_back(Movie(name, rating, watched));
    return true;
}

/*************************************************************************
   increment_watched expects the name of the move to increment the
   watched count

   It will search the movies vector to see if a movie object already exists
   with the same name.
   If it does then increment that objects watched by 1 and return true.

   Otherwise, return false since then no movies object with the movie name
   provided exists to increment
   *********************************************************************/
bool Movies::increment_watched(std::string name) {
    // Searching for the movie
    for (auto& m : movies) {
        if (m.get_name() == name) {
            m.increment_watched();
            return true; 
        }
    }
    return false;
}

/*************************************************************************
    display

    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const {
    // Checking if there are any movies in the list
    if (movies.size() == 0) {
        std::cout << "Sorry, no movies to display" << std::endl;
        std::cout << std::endl;
    }
    // If there are movies, let's display the list
    else {
        std::cout << std::endl;
        std::cout << "======== MOVIE LIST ==========" << std::endl;
        for (const auto& m : movies) {
            m.display();
        }
        std::cout << "==============================" << std::endl;
        std::cout << std::endl;
    }
}