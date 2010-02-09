// $Id$

Drupal.verticalTabs = Drupal.verticalTabs || {};

Drupal.verticalTabs.page_title = function() {
  var pt = $('input#edit-page-title').val();
  if (pt) {
    return Drupal.t('Page title: @pt', { '@pt': pt });
  }
  else {
    return Drupal.t('No page title');
  }
}
