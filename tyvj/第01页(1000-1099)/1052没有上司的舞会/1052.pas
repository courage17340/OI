type
  link=^node;
  node=record
         s:longint;
         next:link;
       end;
var
  rating:array[1..6000] of longint;
  sum:array[0..6000,0..1] of longint;
  son:array[1..6000] of link;
  n,root,i,a,b:longint;
  p:link;
function max(a,b:longint):longint;
begin
   max:=a;if a<b then max:=b;
end;
procedure calc(k:longint);
var
  p:link;
  i:longint;
begin
  sum[k,0]:=0;sum[k,1]:=0;
  p:=son[k];
  while p<>nil do
    begin
      i:=p^.s;
      calc(i);
      sum[k,0]:=sum[k,0]+max(sum[i,0],sum[i,1]);
      sum[k,1]:=sum[k,1]+sum[i,0];
      p:=p^.next;
    end;
  inc(sum[k,1],rating[k]);
end;
begin
  root:=0;
  read(n);
  for i:=1 to n do read(rating[i]);
  for i:=1 to n-1 do
    begin
      read(a,b);
      inc(root,a);
      new(p);
      p^.s:=a;p^.next:=son[b];
      son[b]:=p;
    end;
  root:=(n*(n+1) div 2)-root;
  calc(root);
  writeln(max(sum[root,0],sum[root,1]));
end.