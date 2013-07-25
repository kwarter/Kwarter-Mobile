package com.kwarter.hellokwarter.activity;

import android.app.AlertDialog;
import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.widget.ListView;
import com.kwarter.android.sdk.client.base.ClientError;
import com.kwarter.android.sdk.controller.LobbyLiveEventsObjectController;
import com.kwarter.android.sdk.controller.base.ObjectController;
import com.kwarter.android.sdk.controller.base.ObjectControllerCallback;
import com.kwarter.android.sdk.model.Event;
import com.kwarter.hellokwarter.R;
import com.kwarter.hellokwarter.adapter.LiveEventListAdapter;

import java.util.List;

//
//  LiveEventActivity
//  HelloKwarter
//
//  Created by Elodie Ferrais
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//


public class LiveEventActivity extends FragmentActivity{
    LiveEventListAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.listview);

        ListView listView = (ListView) findViewById(R.id.list);
        adapter = new LiveEventListAdapter(this);
        listView.setAdapter(adapter);

        //Initialize the objectController
        LobbyLiveEventsObjectController liveEventsObjectController = new LobbyLiveEventsObjectController();

        //Fetch locally and remotely the first page of live event with the default page size value (10)
        liveEventsObjectController.fetchFirstPage(ObjectController.FETCH_MODE_BOTH, new ObjectControllerCallback<List<Event>>() {
            @Override
            public void onSuccess(List<Event> events, int fetchMode) {
                // Update the list content
                adapter.setEvents(events);
            }

            @Override
            public void onError(ClientError clientError, int fetchMode) {
                // Alert the user that there is an error
                AlertDialog.Builder builder = new AlertDialog.Builder(LiveEventActivity.this);
                builder.setTitle("Error");
                builder.setMessage("Live event fetching has failed");
                builder.create().show();
            }
        });
    }
}
