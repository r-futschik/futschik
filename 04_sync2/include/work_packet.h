#pragma once


class WorkPacket {
    private:
    int id;

    public:
    WorkPacket(int id){
        this->id = id;
    }

    int get_id() const{
        return this->id;
    }
};