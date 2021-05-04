

from pyecharts.charts import Bar
from pyecharts import options as opts

# 示例数据
cate = ['Apple', 'Huawei', 'Xiaomi', 'Oppo', 'Vivo', 'Meizu']
data1 = [123, 153, 89, 107, 98, 23]
data2 = [56, 77, 93, 68, 45, 67]

# 1.x版本支持链式调用
bar = (Bar()
       .add_xaxis(cate)
       .add_yaxis('电商渠道', data1)
       .add_yaxis( '门铺',data2)
       .set_global_opts(title_opts=opts.TitleOpts(title="Bar-基本示例", subtitle="我是副标题"))
      )
# 在jupyter notebook总渲染
bar.render_notebook()

