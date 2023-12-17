# ESPHome

When a new page is opened, a script name `page_changed` (whith a parameter `page` containing a string with the page name) is called and that one will call a page specific script named `page_<page_name>`. In addition, pages with multiple pages (entitypageXX, buttonpageXX and weatherXX) will also call a generic page named `page_entitypage`, `page_buttonpage` or `page_weather` with a parameter `page_number` containing the number of the page called.

If you want to execute expecific code when a page is opened, you can extend the functionality of that specific page:

```yaml
script:
  - id: !extend page_changed
    then:
      # Code to run when any page is opened
      - lambda: |-
          static const char *const TAG = "script.page_changed (custom)";
          ESP_LOGD(TAG, "Custom code for page changed");
          ESP_LOGD(TAG, "This is the new page: %s", page.c_str());

  - id: !extend page_buttonpage
    then:
      # Code to run when any buttonpage is openend

- id: !extend page_buttonpage02
    then:
      # Code to run when buttonpage02 is opened
```