var
  a:array[0..1001] of longint;
  d:array[0..101] of longint;
  n,m,i,j,k,count:longint;
procedure init;
begin
  readln(m,n);
  fillchar(d,sizeof(d),0);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do read(a[i]);
end;
procedure work;
var t:boolean;
begin
  k:=0;
  count:=0;
  for i:=1 to n do
    begin
      t:=false;
      for j:=1 to k do if a[i]=d[j] then t:=true;
      if not t then
        if k<m then
          begin
            k:=k+1;
            d[k]:=a[i];
            count:=count+1;
          end
          else
            begin
              for j:=1 to m-1 do d[j]:=d[j+1];
              d[m]:=a[i];
              count:=count+1;
            end;
    end;
  writeln(count);
end;
begin
  init;
  work;
end.