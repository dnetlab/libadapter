
include $(TOPDIR)/rules.mk

PKG_NAME:=libadapter
PKG_VERSION:=0.1
PKG_BUILD_DIR:= $(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/libadapter
	SECTION := libs
	CATEGORY := Libraries
	TITLE := router adpater layer for user api
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/
	$(CP) $(PKG_BUILD_DIR)/*.h $(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/libadapter.so $(1)/usr/lib/
endef

define Package/libadapter/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/libadapter.so $(1)/usr/lib
endef

$(eval $(call BuildPackage,libadapter))
