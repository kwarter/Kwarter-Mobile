package com.kwarter.hellokwarter.adapter;

import android.content.Context;
import android.provider.ContactsContract;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;
import com.kwarter.android.sdk.model.Event;
import com.kwarter.android.sdk.model.Participant;
import com.kwarter.hellokwarter.R;

import java.util.List;

//
//  LiveEventListAdapter
//  HelloKwarter
//
//  Created by Elodie Ferrais
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

public class LiveEventListAdapter extends BaseAdapter {
    public List<Event> events;
    public Context context;

    public LiveEventListAdapter(Context context) {
        this.context = context;
    }

    @Override
    public int getCount() {
        if (events == null) {
            return 0;
        }
        return events.size();
    }

    @Override
    public Event getItem(int i) {
        return events.get(i);
    }

    @Override
    public long getItemId(int i) {
        return i;
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {
        View currentCell = view;
        if (currentCell == null) {
            final LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            currentCell = inflater.inflate(R.layout.cell_list, null);

        }
        Event event = getItem(i);

        TextView tv = (TextView) currentCell.findViewById(R.id.title_textview);
        List<Participant> participants = event.getParticipants();
        String cellTitle = null;
        if (participants.size() > 1) {
            Participant firstParticipant = participants.get(0);
            Participant secondParticipant = participants.get(1);
            cellTitle = firstParticipant.getShortName() + " vs " + secondParticipant.getShortName();
        }

        tv.setText(cellTitle);

        return currentCell;
    }

    public void setEvents(List<Event> events) {
        this.events = events;
        notifyDataSetChanged();
    }
}
