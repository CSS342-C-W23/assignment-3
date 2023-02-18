#include "movie_comedy.h"

int MovieComedy::calculate_late_fees(int num_of_days_past_due) {
    //returns the late date fee const multiplied by given num of days past due
    return ((late_fee_per_day)*(num_of_days_past_due));
}
