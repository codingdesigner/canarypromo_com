// $Id: lightbox_login.js,v 1.1.2.2 2008/10/27 15:31:57 snpower Exp $

function lightbox2_login() {
  $("a[@href*='/user/login'], a[@href*='?q=user/login']").each(function() {
    $(this).attr({
      href: this.href.replace(/user\/login?/,"user/login/lightbox2"),
      rel: 'lightmodal[|width:250px; height:220px;]'
    });
  });
}

Drupal.behaviors.initLightboxLogin = function (context) {
  lightbox2_login();
};

