#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due) {
    /*
     * TODO: homework
     */
    if (mercy_rule_apply()) return 0;
    else if (num_of_days_past_due < 5) return num_of_days_past_due * late_fee_per_day;
    else return 2 * (num_of_days_past_due * late_fee_per_day);
}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}