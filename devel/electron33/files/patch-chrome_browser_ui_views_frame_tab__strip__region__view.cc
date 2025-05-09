--- chrome/browser/ui/views/frame/tab_strip_region_view.cc.orig	2024-10-16 21:31:02 UTC
+++ chrome/browser/ui/views/frame/tab_strip_region_view.cc
@@ -205,7 +205,7 @@ TabStripRegionView::TabStripRegionView(std::unique_ptr
 
     // TODO(crbug.com/40118868): Revisit the macro expression once build flag
     // switch of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     // The New Tab Button can be middle-clicked on Linux.
     new_tab_button_->SetTriggerableEventFlags(
         new_tab_button_->GetTriggerableEventFlags() |
