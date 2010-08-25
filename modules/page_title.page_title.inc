<?php

function page_title_page_title_alter(&$title) {
 // If nothing above set a title, give the legacy function a chance to act
  if (empty($title)) {
    $title = page_title_set_title();
  }

  // If we still have no title, fall back to the title provided by Drupal Core
  if (empty($title)) {
    $title = drupal_get_title();
  }
}


function page_title_page_title_pattern_alter(&$pattern, &$data = array()) {
  // If frontpage, then use the frontpage pattern and set the title.
  if (drupal_is_front_page()) {
    // Get the frontpage pattern
    $pattern = variable_get('page_title_front', '[site-name] | [site-slogan]');
  }
}
