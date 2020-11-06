#pragma once
#ifndef WORK_PACKET_H
#define WORK_PACKET_H


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

#endif 