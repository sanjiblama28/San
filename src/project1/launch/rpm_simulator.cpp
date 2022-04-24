<launch>
  <param name="wheel_radius" value="0.125" type="double"/>
  
  <node name="rpm_subscriber_node1" pkg="project1" type="rpm_sub" />
  
  <node name="speed_calculator_node1" pkg="project1" type="speed_calc" />
</launch>
