/* Link header for application - AppBuilder 2.03  */

#if defined(__cplusplus)
extern "C" {
#endif

extern ApContext_t AbContext;

ApWindowLink_t Viewer = {
	"Viewer.wgtw",
	&AbContext,
	AbLinks_Viewer, 0, 1
	};


#if defined(__cplusplus)
}
#endif

