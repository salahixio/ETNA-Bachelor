route "0.0.0.0/0" do
  action :delete
end

route "0.0.0.0/0" do
  gateway node['route']['gateway']
  device node['route']['device']
end
