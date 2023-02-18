#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due) {
    if (num_of_days_past_due <= 0 || mercy_rule_apply()) {
        return 0;
    }
    else if (num_of_days_past_due >= 5)
    {
        return (late_fee_per_day*2) * num_of_days_past_due;
    }
    return late_fee_per_day * num_of_days_past_due;
}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}