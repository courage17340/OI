var
  h:array[0..100] of longint;
  a:array[0..10000] of longint;
  num,i,j,p,q,n:longint;
function f(x:longint):longint;
begin
  f:=x+1;
  if f=10001 then f:=0;
end;
begin
  readln(n);
  fillchar(h,sizeof(h),0);h[0]:=maxlongint;
  fillchar(a,sizeof(a),0);
  num:=0;
  i:=0;
  j:=10000;
  for q:=1 to n do
    begin
      read(p);
      case p of
        1:writeln(num);
        2:begin dec(h[a[i]]);dec(num);i:=f(i);end;
        3:begin read(p);inc(h[p]);j:=f(j);a[j]:=p;inc(num);end;
        4:begin for p:=100 downto 0 do if h[p]>0 then break;writeln(p);end;
      end;
      readln;
    end;
  readln;
end.