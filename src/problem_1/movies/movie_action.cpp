#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due) {
    //We calculate late fees, depending on the type of media
    //the late fee formula changes. If mercy rule applies
    //then late fee is 0
    //if(mercy_rule_apply == true){
    //    return 0;
    //}
    return ((num_of_days_past_due)*(late_fee_per_day));
}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}