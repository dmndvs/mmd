<div class="clearfix <?php print $row;?>">
  <div class="mmd-img"><a href="<?php print $src_path . $img;?>"><img src="<?php print $thumbnail_path . $img;?>"></a></div>
  <div class="mmd-content">
    <div class="mmd-title clearfix"><?php if($importance == '1'):?>
      <img src="<?php print $thumbnail_path . $imp_img;?>">
      <?php endif; print '<h2>'.$title.'</h2>';?></div>
    <div class="mmd-created"><?php print $created;?></div>
    <div class="mmd-data"><?php print $data;?></div>
    <?php if(isset($read_more)) : ?>
    <div class="mmd-read-more"><?php print $read_more;?></div>
    <?php endif; ?>
  </div>
</div>