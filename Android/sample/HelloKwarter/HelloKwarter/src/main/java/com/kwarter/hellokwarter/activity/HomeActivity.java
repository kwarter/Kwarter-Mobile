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
import com.kwarter.hellokwarter.adapter.HomeListAdapter;
import com.kwarter.hellokwarter.adapter.LiveEventListAdapter;

import java.util.List;

//
//  HomeActivity
//  HelloKwarter
//
//  Created by Elodie Ferrais
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

public class HomeActivity extends FragmentActivity {

    HomeListAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.listview);

        ListView listView = (ListView) findViewById(R.id.list);
        adapter = new HomeListAdapter(this);
        listView.setAdapter(adapter);
        listView.setOnItemClickListener(adapter);
    }
}
