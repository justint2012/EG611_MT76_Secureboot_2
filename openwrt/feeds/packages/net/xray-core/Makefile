include $(TOPDIR)/rules.mk

PKG_NAME:=xray-core
PKG_VERSION:=1.6.5
PKG_RELEASE:=$(AUTORELEASE)

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/XTLS/Xray-core/tar.gz/v$(PKG_VERSION)?
PKG_HASH:=61956d8d72d086fbf83e6a3aff191d010401aca34f30015f839f8a73bf50914c

PKG_MAINTAINER:=Tianling Shen <cnsztl@immortalwrt.org>
PKG_LICENSE:=MPL-2.0
PKG_LICENSE_FILES:=LICENSE

PKG_BUILD_DIR:=$(BUILD_DIR)/Xray-core-$(PKG_VERSION)
PKG_BUILD_DEPENDS:=golang/host
PKG_BUILD_PARALLEL:=1
PKG_USE_MIPS16:=0

GO_PKG:=github.com/xtls/xray-core
GO_PKG_BUILD_PKG:=github.com/xtls/xray-core/main
GO_PKG_LDFLAGS_X:= \
	$(GO_PKG)/core.build=OpenWrt \
	$(GO_PKG)/core.version=$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include ../../lang/golang/golang-package.mk

define Package/xray/template
  TITLE:=A platform for building proxies to bypass network restrictions
  SECTION:=net
  CATEGORY:=Network
  URL:=https://xtls.github.io
endef

define Package/xray-core
  $(call Package/xray/template)
  DEPENDS:=$(GO_ARCH_DEPENDS) +ca-bundle
endef

define Package/xray-example
  $(call Package/xray/template)
  TITLE+= (example configs)
  DEPENDS:=xray-core
  PKGARCH:=all
endef

define Package/xray-geodata
  $(call Package/xray/template)
  TITLE+= (geodata files)
  DEPENDS:=xray-core
  PKGARCH:=all
endef

define Package/xray/description
  Xray, Penetrates Everything. It helps you to build your own computer network.
  It secures your network connections and thus protects your privacy.
endef

define Package/xray-core/description
  $(call Package/xray/description)
endef

define Package/xray-example/description
  $(call Package/xray/description)

  This includes example configuration files for xray-core.
endef

define Package/xray-geodata/description
  $(call Package/xray/description)

  This includes GEO datas used for xray-core.
endef

define Package/xray-core/conffiles
/etc/xray/
/etc/config/xray
endef

GEOIP_VER:=202211240054
GEOIP_FILE:=geoip.dat.$(GEOIP_VER)
define Download/geoip
  URL:=https://github.com/v2fly/geoip/releases/download/$(GEOIP_VER)/
  URL_FILE:=geoip.dat
  FILE:=$(GEOIP_FILE)
  HASH:=567c9a1bfe22c2ff7f468f3814aa6bb344b33393cf39507e5cbeb20c78c952b7
endef

GEOSITE_VER:=20221127082021
GEOSITE_FILE:=dlc.dat.$(GEOSITE_VER)
define Download/geosite
  URL:=https://github.com/v2fly/domain-list-community/releases/download/$(GEOSITE_VER)/
  URL_FILE:=dlc.dat
  FILE:=$(GEOSITE_FILE)
  HASH:=519583c593fada6cf8d629eb428652199ab715d641073f64122c1e2c68b6c43f
endef

define Build/Prepare
	$(call Build/Prepare/Default)
ifneq ($(CONFIG_PACKAGE_xray-geodata),)
	$(call Download,geoip)
	$(call Download,geosite)
endif
endef

define Package/xray-core/install
	$(call GoPackage/Package/Install/Bin,$(PKG_INSTALL_DIR))
	$(INSTALL_DIR) $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/main $(1)/usr/bin/xray

	$(INSTALL_DIR) $(1)/etc/xray/
	$(INSTALL_DATA) $(CURDIR)/files/config.json.example $(1)/etc/xray/

	$(INSTALL_DIR) $(1)/etc/config/
	$(INSTALL_CONF) $(CURDIR)/files/xray.conf $(1)/etc/config/xray
	$(INSTALL_DIR) $(1)/etc/init.d/
	$(INSTALL_BIN) $(CURDIR)/files/xray.init $(1)/etc/init.d/xray
endef

define Package/xray-example/install
	$(INSTALL_DIR) $(1)/etc/xray/
	$(INSTALL_DATA) $(CURDIR)/files/vpoint_socks_vmess.json $(1)/etc/xray/
	$(INSTALL_DATA) $(CURDIR)/files/vpoint_vmess_freedom.json $(1)/etc/xray/
endef

define Package/xray-geodata/install
	$(INSTALL_DIR) $(1)/usr/share/xray/
	$(INSTALL_DATA) $(DL_DIR)/$(GEOIP_FILE) $(1)/usr/share/xray/geoip.dat
	$(INSTALL_DATA) $(DL_DIR)/$(GEOSITE_FILE) $(1)/usr/share/xray/geosite.dat
endef

$(eval $(call BuildPackage,xray-core))
$(eval $(call BuildPackage,xray-example))
$(eval $(call BuildPackage,xray-geodata))
