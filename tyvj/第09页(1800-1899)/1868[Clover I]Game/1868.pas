type
  ty=^node;
  node=record
         t:char;
         pre,next:ty;
       end;
var
  a,b,p,head,tail,hh:^node;
  s:ansistring;
  i,k,n,L:longint;
procedure print;
begin
  while (head^.t='0')and(head<>tail) do head:=head^.next;
  if head=tail then write(0);
  while head<>tail do
    begin
      write(head^.t);
      head:=head^.next;
    end;
  writeln;
  readln;
  halt;
end;
begin
  new(hh);
  readln(s);
  L:=length(s);
  s:=s+chr(47);
  new(a);
  a^.t:=s[1];
  a^.pre:=hh;
  head:=a;
  for i:=2 to L do
    begin
      new(p);
      a^.next:=p;
      p^.pre:=a;
      p^.t:=s[i];
      a:=p;
    end;
  new(p);
  a^.next:=p;
  p^.t:='/';
  p^.pre:=a;
  tail:=p;
  p:=head;
  readln(n);
  k:=0;
  while true do
    begin
      if p=tail^.pre then begin for i:=1 to n-k-1 do p:=p^.pre;print;end;
      while (p<>tail^.pre)and(p^.t<=p^.next^.t) do p:=p^.next;
      while p^.t>p^.next^.t do
        begin
          p^.pre^.next:=p^.next;
          p^.next^.pre:=p^.pre;
          b:=p^.pre;
          if p=head then head:=head^.next;
          dispose(p);
          p:=b;
          if p=hh then p:=head;
          inc(k);
          if k=n then print;
        end;
    end;
end.