#
# Cookbook Name:: proxyconf
# Recipe:: default
#
# Copyright (c) 2016 The Authors, All Rights Reserved.

execute 'enable_site' do
  command 'sudo ln -s /etc/nginx/sites-available/balancing /etc/nginx/sites-enabled/'
  action :nothing
end

execute 'delete_default' do
  command 'sudo rm /etc/nginx/sites-enabled/default'
  action :nothing
end

service 'nginx' do
  supports :status => true, :restart => true, :reload => true
end

template '/etc/nginx/sites-available/balancing' do
  source 'balancing'
  notifies :run, 'execute[enable_site]', :immediately
  notifies :run, 'execute[delete_default]', :immediately
  notifies :restart, 'service[nginx]', :immediately
end
