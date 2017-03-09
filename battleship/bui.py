import arcade

arcade.open_window("Battleship", 600, 600)

arcade.set_background_color(arcade.color.WHITE)

arcade.start_render()

# Draw a grid
# Draw vertical lines every 120 pixels
text_offset = 500
row_number = 1
arcade.draw_text("Simple line of text in 12 point", 50, 50, arcade.color.BLACK, 12)
for x in range(0, 661, 60):
    arcade.draw_line(x, 0, x, 600, arcade.color.BLACK, 2)
    arcade.draw_text(text="{}".format(row_number), 
                     start_x=40, 
                     start_y=text_offset, 
                     color=arcade.color.BLACK,
                     font_size=12)
    text_offset -= 50
    row_number += 1

# Draw horizontal lines every 200 pixels
for y in range(0, 661, 60):
    arcade.draw_line(0, y, 800, y, arcade.color.BLACK, 2)
    
arcade.finish_render()
arcade.run()