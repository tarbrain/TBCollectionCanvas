//
//  TBCollectionCanvasContentView.h
//
//  Created by Julian Krumow on 23.01.12.
//
//  Copyright (c) 2012 Julian Krumow ()
//
//


#import <UIKit/UIKit.h>

#import "TBCanvasNodeView.h"
#import "TBCollectionCanvasContentViewDataSource.h"
#import "TBCollectionCanvasContentViewDelegate.h"
#import "TBCollectionCanvasController.h"

@class TBCollectionCanvasView;

/**
 This class represents a canvas for node items in a collection.
 Items can be dragged, inserted, deleted etc.
 
 */
@interface TBCollectionCanvasContentView : UIView <CanvasNodeViewDelegate, CanvasNodeConnectionDelegate, CanvasNewConnectionHandleDelegate, CanvasMoveConnectionHandleDelegate> {
    
    CGFloat zoomScale;
}

@property (assign, nonatomic) id<TBCollectionCanvasContentViewDataSource> canvasViewDataSource;
@property (assign, nonatomic) id<TBCollectionCanvasContentViewDelegate> canvasViewDelegate;

@property (weak, nonatomic) TBCollectionCanvasView *scrollView;
@property (strong, nonatomic) TBCollectionCanvasController *canvasController;

@property (assign, nonatomic, getter = isMenuEnabled) BOOL menuEnabled;

@property (assign, nonatomic, readonly, getter=isLockedToSingleTouch) BOOL lockedToSingleTouch;

/** @name Managing the CollectionCanvasView's content */

/**
 Fills the TBCollectionCanvasContentView with TBCanvasNodeView objects.
 */
- (void)fillCanvas;

/**
 Clears the canvas.
 Removes all CanvasNodeViews from view and from nodeViews array. 
 */
- (void)clearCanvas;

/**
 Reloads all items on the TBCollectionCanvasContentView.
 */
- (void)reloadCanvas;

/**
 Resizes the canvas view to an optimal size (optimal >= minimum size).
 */
- (void)sizeCanvasToFit;

/**
 Redraws all CanvasNodeViews and CanvasNodeConnections on the TBCollectionCanvasContentView in the actual zoomScale.
 
 @param scale The given zoom scale.
 */
- (void)zoomToScale:(CGFloat)scale;

/**
 Updates a single item on the TBCollectionCanvasContentView.
 
 @param indexPath The index path of the given TBCanvasNodeView object.
 */
- (void)updateNodeViewAtIndexPath:(NSIndexPath *)indexPath;

/**
 Inserts a node with a given index.
 
 @param indexPath The index path of the given TBCanvasNodeView object.
 */
- (void)insertNodeAtIndexPath:(NSIndexPath *)indexPath;

/**
 Deletes a node with a given index.
 
 @param indexPath The index path of the given TBCanvasNodeView object.
 */
- (void)deleteNodeAtIndexPath:(NSIndexPath *)indexPath;

/**
 Returns a TBCanvasNodeView with a given index.
 
 @param indexPath The index path of the given TBCanvasNodeView object.
 
 @return The specified TBCanvasNodeView object.
 */
- (TBCanvasNodeView *)nodeAtIndexPath:(NSIndexPath *)indexPath;


/** @name Controlling the TBCollectionCanvasContentView */

/**
 Toggles connection mode on and off.
 */
- (void)toggleConnectMode;

/**
 Returns `YES` when the TBCollectionCanvasContentView is currently processing subviews (tapping, dragging etc.).
 
 @return `YES` when subview are processed.
 */
- (BOOL)isProcessingViews;

/**
 Returns `YES`when the view is locked to processing of only one view.
 
 @return `YES`when the view is locked to processing of only one view.
 */
- (BOOL)isInSingleTouchMode;

/**
 Hides the menu to delete, collapse / expand the selected item.
 */
- (void)hideMenu;

@end