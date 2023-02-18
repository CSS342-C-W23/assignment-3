#pragma once

class StoreMediaInterface {
public:
    int get_late_fee_per_day_in_dollar() {
        return late_fee_per_day_in_dollar;
    }

    size_t get_inventory_id() const {
        return inventory_id;
    }

    virtual int calculate_late_fees(int num_of_days_past_due) {
        if (num_of_days_past_due <= 0 || mercy_rule_apply()) {
            return 0;
        }
        return late_fee_per_day_in_dollar * num_of_days_past_due;
    }

    virtual bool mercy_rule_apply() {
        //According to unit test, this formula is used
        //to determine if mercy rule is applied
        //action_movie_mercy_rule_apply()
        if(get_inventory_id() % 13 == 0){
            return true;
        }
        //Returns false otherwise
        return false;
    }

    bool operator==(const StoreMediaInterface &other_media) const {

        //Checks if they are the same type of media
        if(other_media == *this){
            //Checks if they have the same ID, if so they are the same
            if(get_inventory_id() == other_media.get_inventory_id()){
            return true;
        }
        //Returns false otherwise
        return false;
    }
    }

    bool operator!=(const StoreMediaInterface &other_media) const {
        return !(other_media == *this);
    }

    virtual ~StoreMediaInterface() {};

protected:
    int late_fee_per_day_in_dollar = 2;
    size_t inventory_id;

    void set_late_fee_per_day_in_dollar(int fee) {
        this->late_fee_per_day_in_dollar = fee;
    }
};