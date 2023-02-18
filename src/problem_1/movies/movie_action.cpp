#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due) {
    int base_fee = num_of_days_past_due * this ->get_late_fee_per_day_in_dollar();
    int fee = 0;
    if(num_of_days_past_due >= 5) {
        fee = 2 * base_fee;
    } else {
         fee = base_fee;
    }
    bool has_mercy = false;
    if(this ->get_inventory_id() % 13 == 0 && this ->action_movie_mercy_rule_apply()){
        has_mercy = true;
    }

    if(has_mercy) {
        return 0;
    } else {
        return fee;
    }

}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}