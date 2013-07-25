package com.kwarter.hellokwarter.adapter;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.kwarter.hellokwarter.R;
import com.kwarter.hellokwarter.activity.LiveEventActivity;


//
//  LiveEventActivity
//  HelloKwarter
//
//  Created by Elodie Ferrais
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

public class HomeListAdapter extends BaseAdapter implements AdapterView.OnItemClickListener{

   Context context;
   String[] menuTitle = {"Live Events"};
   Class[] activities = {LiveEventActivity.class};

    public HomeListAdapter(Context context) {
        this.context = context;
    }

    @Override
    public int getCount() {
        return menuTitle.length;
    }

    @Override
    public String getItem(int i) {
        return menuTitle[i];
    }

    @Override
    public long getItemId(int i) {
        return 0;
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {
        View currentCell = view;
        if (currentCell == null) {
            final LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            currentCell = inflater.inflate(R.layout.cell_list, null);
        }

        TextView tv = (TextView) currentCell.findViewById(R.id.title_textview);
        tv.setText(getItem(i));

        return  currentCell;
    }

    @Override
    public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
        Intent intent = new Intent(context, activities[0]);
        context.startActivity(intent);
    }
}
